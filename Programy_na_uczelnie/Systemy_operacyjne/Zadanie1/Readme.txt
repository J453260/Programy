W moim systemie osierocone procesy adoptuje process "system", który ma PID 1.

Przy n-krotnym wywołaniu funkcji fork() powstanie 2^n procesów, ponieważ każdy proces (proces macieżysty) tworzy nowy process, czyli są 2 procesy. W kolejnym wywołaniu funkcji tworzone są 2 nowe procesy, są już 4. Każdy z tych 4 procesów przy 3 wywołaniu stworzy kolejny, więc będzie ich 8.