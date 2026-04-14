"""
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
%matplotlib inline

import bokeh.io, bokeh.plotting
bokeh.io.output_notebook()

import sklearn
from sklearn import linear_model, metrics, model_selection

# Download the dataset
!wget https://krzysztof.kutt.pl/didactics/psaw/kc_house_data_train.csv
!wget https://krzysztof.kutt.pl/didactics/psaw/kc_house_data_test.csv

# ── 1. Load the dataset ───────────────────────────────────────────────────────
houses = pd.read_csv('kc_house_data_train.csv')

# ── 2. Initial exploration ────────────────────────────────────────────────────
print("=== First few rows ===")
display(houses.head())

print("\n=== Descriptive statistics ===")
display(houses.describe())

# ── 3. Scatterplots ───────────────────────────────────────────────────────────
fig, axes = plt.subplots(1, 2, figsize=(14, 5))

# Plot 1: sqft_living vs price
axes[0].scatter(houses['sqft_living'], houses['price'],
                alpha=0.3, s=10, color='steelblue')
axes[0].set_xlabel('Living Area (sqft)', fontsize=12)
axes[0].set_ylabel('Price ($)', fontsize=12)
axes[0].set_title('Living Area vs Price', fontsize=14)
axes[0].yaxis.set_major_formatter(
    plt.FuncFormatter(lambda x, _: f'${x/1e6:.1f}M'))

# Plot 2: bathrooms vs price
axes[1].scatter(houses['bathrooms'], houses['price'],
                alpha=0.3, s=10, color='darkorange')
axes[1].set_xlabel('Number of Bathrooms', fontsize=12)
axes[1].set_ylabel('Price ($)', fontsize=12)
axes[1].set_title('Bathrooms vs Price', fontsize=14)
axes[1].yaxis.set_major_formatter(
    plt.FuncFormatter(lambda x, _: f'${x/1e6:.1f}M'))

plt.tight_layout()
plt.show()
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import urllib.request

# ── 1. Pobranie danych (jeśli jeszcze nie masz pliku) ─────────────────────────
url = "https://krzysztof.kutt.pl/didactics/psaw/kc_house_data_train.csv"
filename = "kc_house_data_train.csv"

try:
    with open(filename, "r"):
        print("Plik już istnieje, pomijam pobieranie.")
except FileNotFoundError:
    print("Pobieram dane...")
    urllib.request.urlretrieve(url, filename)

# ── 2. Wczytanie danych ───────────────────────────────────────────────────────
houses = pd.read_csv(filename)

# ── 3. Podstawowa analiza ─────────────────────────────────────────────────────
print("=== First few rows ===")
print(houses.head())

print("\n=== Descriptive statistics ===")
print(houses.describe())

# ── 4. Wykresy ────────────────────────────────────────────────────────────────
fig, axes = plt.subplots(1, 2, figsize=(14, 5))

# Plot 1: sqft_living vs price
axes[0].scatter(houses['sqft_living'], houses['price'],
                alpha=0.3, s=10)
axes[0].set_xlabel('Living Area (sqft)')
axes[0].set_ylabel('Price ($)')
axes[0].set_title('Living Area vs Price')

# Plot 2: bathrooms vs price
axes[1].scatter(houses['bathrooms'], houses['price'],
                alpha=0.3, s=10)
axes[1].set_xlabel('Number of Bathrooms')
axes[1].set_ylabel('Price ($)')
axes[1].set_title('Bathrooms vs Price')

plt.tight_layout()
plt.show()