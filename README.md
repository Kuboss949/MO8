# MO8
Napisz program w języku „C/C++”, obliczający przybliżone wartości pierwszych pochodnych
funkcji f(x) = sin(x) w punktach końcowych i środkowym przedziału [0, /2] zmiennej x. Zastosuj
wszystkie omawiane na wykładzie i na ćwiczeniach przybliżenia różnicowe dwupunktowe i
trzypunktowe (jednostronne bądź centralne, w zależności od położenia punktu w przedziale) na sieci
jednorodnej o kroku h. Wykonaj (na jednym rysunku) wykresy przedstawiające zależności błędów
bezwzględnych przybliżeń różnicowych od kroku sieci, posługując się skalą logarytmiczną (tzn.
wykresy zależności log10|błędu| od log10 h ). Na podstawie wykresów wyznacz doświadczalnie rzędy
dokładności przybliżeń różnicowych. Sprawdź, czy tak wyznaczone rzędy dokładności pokrywają
się z rzędami teoretycznymi i wyjaśnij ewentualne rozbieżności. Ponadto zidentyfikuj wartości
kroku sieci poniżej których pojawia się wpływ błędów maszynowych. Obliczenia powtórz dla
dwóch typów zmiennych rzeczywistych (float, i double) i porównaj wyniki.
Uwaga: najwygodniej jest zastosować wzorzec funkcji (function template) z typem zmiennych jako
parametrem wzorca.
