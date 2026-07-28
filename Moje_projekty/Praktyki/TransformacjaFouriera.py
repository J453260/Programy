import numpy as np
from scipy.integrate import quad
import matplotlib.pyplot as plt

""" Definicja funkcji f(t)=t
def f(t):
    if np.abs(t) < 1:
        return t
    elif np.abs(t) == 1:
        return 0.5 * np.sign(t)
    else:
        return 0
"""


# Definicja funkcji f(t) - impuls prostokątny
def f(t):
    if abs(t) < 1:
        return 1
    elif abs(t) == 1:
        return 0.5 * np.sign(t)
    else:
        return 0


# Definicja transformacji Fouriera
def fourier_transform(omega):
    integrand = lambda t: f(t) * np.exp(-1j * omega * t)
    real_part = quad(lambda t: np.real(integrand(t)), -np.inf, np.inf)[0]
    imag_part = quad(lambda t: np.imag(integrand(t)), -np.inf, np.inf)[0]
    return real_part + 1j * imag_part


# Zakres częstotliwości omega
N = 10
omega_values = np.linspace(-N, N, 500)
fourier_values = np.array([fourier_transform(omega) for omega in omega_values])

# Wykresy: Re, Im oraz |F(ω)|
plt.figure(figsize=(14, 20))

# Wykres części rzeczywistej
plt.subplot(3, 1, 1)
plt.plot(
    omega_values, fourier_values.real, label=r"Re$\{\hat{f}(\omega)\}$", color="blue"
)
plt.title("Część rzeczywista transformaty Fouriera", fontsize=30)
plt.xlabel(r"$\omega$", fontsize=20)
plt.ylabel(r"Re$\{\hat{f}(\omega)\}$", fontsize=14)
plt.grid(True)
plt.legend(fontsize=20)

# Wykres części urojonej
plt.subplot(3, 1, 2)
plt.plot(
    omega_values, fourier_values.imag, label=r"Im$\{\hat{f}(\omega)\}$", color="red"
)
plt.title("Część urojona transformaty Fouriera", fontsize=30)
plt.xlabel(r"$\omega$", fontsize=20)
plt.ylabel(r"Im$\{\hat{f}(\omega)\}$", fontsize=14)
plt.grid(True)
plt.legend(fontsize=20)

# Wykres modułu |F(ω)|
plt.subplot(3, 1, 3)
plt.plot(
    omega_values, np.abs(fourier_values), label=r"$|\hat{f}(\omega)|$", color="green"
)
plt.title("Moduł transformaty Fouriera", fontsize=30)
plt.xlabel(r"$\omega$", fontsize=20)
plt.ylabel(r"$|\hat{f}(\omega)|$", fontsize=14)
plt.grid(True)
plt.legend(fontsize=20)

plt.tight_layout()
plt.show()
