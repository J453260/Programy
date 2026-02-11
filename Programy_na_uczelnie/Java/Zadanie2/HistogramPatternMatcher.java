import java.util.*;

class HistogramPatternMatcher extends AbstractHistogramPatternMatcher {

    private Map<Integer, Integer> histogramMap = new TreeMap<>();
    private Map<Integer, Integer> PelnyHistogram = new TreeMap<>();

    @Override
    public void data(int value) {
        histogramMap.put(value, histogramMap.getOrDefault(value, 0) + 1);
    }

    @Override
    public Map<Integer, Integer> histogram() {
        if (histogramMap.isEmpty()) {
            return new TreeMap<>();
        }

        Map<Integer, Integer> result = new TreeMap<>();
        for (Map.Entry<Integer, Integer> entry : histogramMap.entrySet()) {
            if (entry.getValue() > 0) { // tylko liczby zliczone
                result.put(entry.getKey(), entry.getValue());
            }
        }
        return result;
    }

    @Override
    public Set<Integer> match(List<Integer> pattern) {
        Set<Integer> result = new TreeSet<>();
        if (pattern == null || pattern.isEmpty() || histogramMap.isEmpty()) return result;


        PelnyHistogram.clear();
        PelnyHistogram.putAll(histogramMap);

        int min = Collections.min(histogramMap.keySet());
        int max = Collections.max(histogramMap.keySet());
        //minimalna i maksymalna wartość wczytana metodą data


        for (int i = min; i <= max; i++) {
            PelnyHistogram.putIfAbsent(i, 0);
            //wypełnianie histogramu liczbami, które nie wystąpiły w przedziale [min, max]
        }

        int patternSize = pattern.size();
        if (patternSize > (max - min + 1)) {
            return result;
            //zwraca pusty wynik gdy wzorzec jest dłuższy niż zakres danych
        }

        // Lista uporządkowanych kluczy
        //List<Integer> keys = List.copyOf(fullHistogram.keySet());

        // Szukamy dopasowań
        for (int i = min; i <= max - patternSize + 1; i++) {
            boolean matchFlag = true;

            for (int j = 0; j < patternSize - 1; j++) {

                if (!PelnyHistogram.containsKey(i + j) || !PelnyHistogram.containsKey(i + j + 1)) {
                    matchFlag = false;
                    break;
                }

                int val1 = PelnyHistogram.get(i + j);
                int val2 = PelnyHistogram.get(i + j + 1);

                int pat1 = pattern.get(j);
                int pat2 = pattern.get(j + 1);

                if (pat1 == 0 && pat2 == 0) {
                    if (!(val1 == 0 && val2 == 0)) {
                        matchFlag = false;
                        break;
                    }
                    continue;
                }

                if (pat1 == 0 || pat2 == 0) {
                    if ((pat1 == 0 && val1 != 0) || (pat2 == 0 && val2 != 0)) {
                        matchFlag = false;
                        break;
                    }
                    continue;
                }

                if (val1 == 0 && val2 == 0) {
                    if (pat1 != pat2) {
                        matchFlag = false;
                        break;
                    }
                    continue;
                }

                if (val1 == 0 || val2 == 0) {
                    matchFlag = false;
                    break;
                }

                if (val2 * pat1 != val1 * pat2) {
                    matchFlag = false;
                    break;
                }

            }

            if (matchFlag) result.add(i);
        }

        return result;
    }

    // Main do testowania
    public static void main(String[] args) {
        AbstractHistogramPatternMatcher matcher = new HistogramPatternMatcher();
        int[] dane = {5, 3, 4, 2, 5, 5, 4, -1, -2, 2, 3, 4};
        for (int v : dane) matcher.data(v);

        System.out.println("Histogram:");
        System.out.println(matcher.histogram());
        System.out.println("Match [1,1]: " + matcher.match(List.of(1, 1)));
        System.out.println("Match [1,2]: " + matcher.match(List.of(1, 2)));
        System.out.println("Match [0,0]: " + matcher.match(List.of(0, 0)));
    }
}