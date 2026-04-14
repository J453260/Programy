# Drop non-predictive columns: target + identifiers + date
exclude_cols = ['price', 'id', 'date']
all_features = [c for c in houses_train.select_dtypes(include=[np.number]).columns
                if c not in exclude_cols]

print(f"Features used ({len(all_features)}):", all_features)

X_train_all = houses_train[all_features]
X_test_all  = houses_test[all_features]

regr_all = linear_model.LinearRegression()
regr_all.fit(X_train_all, y_train)

pred_all = regr_all.predict(X_test_all)
mse_all  = metrics.mean_squared_error(y_test, pred_all)
rmse_all = np.sqrt(mse_all)

# ── Summary comparison across all tasks ──────────────────
print("\nTASK 4 — Full feature model")
print("\n" + "=" * 52)
print(f"  {'Model':<30} {'RMSE':>15}")
print("=" * 52)
print(f"  {'bathrooms only':<30} ${rmse_bathrooms:>14,.0f}")
print(f"  {'sqft_living only':<30} ${rmse_sqft:>14,.0f}")
print(f"  {'sqft_living + bedrooms':<30} ${rmse_2:>14,.0f}")
print(f"  {'all features':<30} ${rmse_all:>14,.0f}")
print("=" * 52)

best_gain = (1 - rmse_all / rmse_bathrooms) * 100
print(f"\n  Overall improvement (vs worst): {best_gain:.1f}%")