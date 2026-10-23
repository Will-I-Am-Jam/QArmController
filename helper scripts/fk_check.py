"""Quick QArm forward-kinematics checker (Python port of qarmForwardKinematics.m).

Usage:
    python fk_check.py phi1 phi2 phi3 phi4 [dphi1 dphi2 dphi3 dphi4]

    phi    - joint angles in DEGREES
    dphi   - joint velocities in rad/s (optional, default 0)

Examples:
    python fk_check.py 0 0 0 0                 # home
    python fk_check.py 0 20 10 0 0.8 0 0 0     # base swing at 0.8 rad/s

Prints p4 (m) and v4 (m/s) in frame {0}, ready to paste into MATLAB.
NOTE: this is a copy of the equations, not a call to the .m file. If you
change qarmForwardKinematics.m, update this too.
"""
import sys
from math import atan, cos, hypot, pi, radians, sin

# Manipulator dimensions (m) -- keep in sync with qarmForwardKinematics.m
L1, L2, L3, L4, L5 = 0.14, 0.35, 0.05, 0.25, 0.15
l1 = L1
l2 = hypot(L2, L3)
l3 = L4 + L5
beta = atan(L3 / L2)


def dh(a, alpha, d, theta):
    ct, st, ca, sa = cos(theta), sin(theta), cos(alpha), sin(alpha)
    return [[ct, -st * ca, st * sa, a * ct],
            [st, ct * ca, -ct * sa, a * st],
            [0, sa, ca, d],
            [0, 0, 0, 1]]


def matmul(A, B):
    return [[sum(A[i][k] * B[k][j] for k in range(4)) for j in range(4)]
            for i in range(4)]


def cross(a, b):
    return [a[1] * b[2] - a[2] * b[1],
            a[2] * b[0] - a[0] * b[2],
            a[0] * b[1] - a[1] * b[0]]


def fk(phi, phi_dot):
    """phi in rad, phi_dot in rad/s -> (p4, v4)."""
    theta = [phi[0], phi[1] + beta - pi / 2, phi[2] - beta, phi[3]]
    Ts = [dh(0, -pi / 2, l1, theta[0]),
          dh(l2, 0, 0, theta[1]),
          dh(0, -pi / 2, 0, theta[2]),
          dh(0, 0, l3, theta[3])]

    T = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
    origins = [[0, 0, 0]]
    axes = [[0, 0, 1]]
    for A in Ts:
        T = matmul(T, A)
        origins.append([T[i][3] for i in range(3)])
        axes.append([T[i][2] for i in range(3)])

    p4 = origins[-1]
    v4 = [0.0, 0.0, 0.0]
    for i in range(4):
        col = cross(axes[i], [p4[k] - origins[i][k] for k in range(3)])
        v4 = [v4[k] + col[k] * phi_dot[i] for k in range(3)]
    return p4, v4


def fmt(v):
    return "[" + "; ".join(f"{x:.3f}" for x in v) + "]"


if __name__ == "__main__":
    args = [float(x) for x in sys.argv[1:]]
    if len(args) not in (4, 8):
        sys.exit(__doc__)
    phi = [radians(x) for x in args[:4]]
    phi_dot = args[4:] if len(args) == 8 else [0.0] * 4
    p4, v4 = fk(phi, phi_dot)
    print(f"p_goal = {fmt(p4)};   % m")
    print(f"v_goal = {fmt(v4)};   % m/s")
