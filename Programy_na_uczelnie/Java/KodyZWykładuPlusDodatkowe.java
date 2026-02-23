/**
import java.awt.*;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.lang.annotation.Annotation;
import java.util.Collections;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.function.LongConsumer;
import java.util.zip.GZIPOutputStream;
import static java.lang.Thread.sleep;
 */

/**
class Inkrementacja{
    public static void main(String[] argv){
        int i = 0;
        System.out.println("i = " + (i++));
        System.out.println("i = " + i);
        System.out.println("i = " + (++i));
        System.out.println("i = " + i);
        i+=2;
        System.out.println("i = " + i);
        i*=2;
        System.out.println("i = " + i);
        i%=6;
        System.out.println("i = " + i);
    }
}
 */

/**
public class Priorytety {
    public static void main(String[] argv){
        int a = 9;
        int b = 19;
        int c = 29;
        int wynik = 0;

        wynik = Echo.echo(++a, wynik)*Echo.echo(++b, wynik)*Echo.echo(++c, wynik);
        System.out.println("Wynik to: " + wynik);
    }
}

class Echo{
    public static int echo(int input, int wynik){
        System.out.println(" echo " + input + " wynik " + wynik);
        return input;
    }
 }
*/

/**
class Incrementer{
    public int counter;
    private boolean changed;

    public void showIfChanged() {
        if (changed) {
            System.out.println("Counter = " + counter);
            changed = false;
        }
    }

    public void inc() {
        counter++;
        changed = true;
    }
}

class Tester {
    public static void main(String[] argv) {
        Incrementer ii = new Incrementer();
        ii.inc();                // counter = 1, changed = true
        ii.showIfChanged();      // wypisze: Counter = 1, changed = false
        ii.counter++;            // counter = 2, changed nadal = false
        ii.showIfChanged();      // nic nie wypisze, bo changed = false
        ii.inc();                // counter = 3, changed = true
        ii.showIfChanged();      // wypisze: Counter = 3, changed = false
    }
}
*/

/**
class Incrementer{
    private int counter = 1;
    public Incrementer(){
        System.out.println("Incrementer: Bylo: " + counter);
        counter = 10;
        System.out.println("Incrementer: Jest: " + counter);
    }

    public Incrementer(int ini){
        this();
        System.out.println("Incrementer(int): Bylo: " + counter);
        counter = ini;
        System.out.println("Incrementer(int): Jest: " + counter);
    }

    public static void main(String[] argv){
        new Incrementer(100);
    }
}
*/

/**
class Konstruktor25{
    public Konstruktor25(){
        System.out.println("Konstruktor bezparametrowy");
    }

    public Konstruktor25(String txt){
        System.out.println("Prolog konstruktora z parametrem String " + txt);
        this();
        System.out.println("Epilog konstruktora z parametrem String " + txt);
    }

    public static void main(String[] argv){
        new Konstruktor25("25");
    }
}
 */

/**
class KonstruktorProlog {
    int j = 10;
    int k;

    public KonstruktorProlog() {
        System.out.println("Prolog konstruktora bezparametrowego");
        // k = this.j;     // NIE wolno, bo obiekt jeszcze nie jest gotowy
        k = 10;            // WOLNO, bo to tylko inicjacja
        // this(k);        // NIE wolno, bo konstrukcja jeszcze w toku
        int l = 12 * 21;   // WOLNO
        this(l);           // WOLNO
        System.out.println("Epilog konstruktora bezparametrowego");
    }

    public KonstruktorProlog(int i) {
        System.out.println("Konstruktor z parametrem otrzymal " + i);
    }

    public static void main(String[] args) {
        new KonstruktorProlog();
    }
}
 */

/**
class Incrementer {
    private int counter = 1;

    public Incrementer(Incrementer inc) { // oto konstr. kopiujacy
        counter = inc.counter; // to jest wazna linijka
        System.out.println("Incrementer(Incrementer): Jest : " + counter);
    }

    public Incrementer(int ini) {
        counter = ini;
        System.out.println("Incrementer(int): Jest : " + counter);
    }

    public static void main(String[] argv) {
        new Incrementer(new Incrementer(5));
    }
}
 */

/**
class Incrementer{
    private int counter = 1;

    {
        System.out.println("Tu blok 1: Bylo: " + counter);
        counter = 10;
        System.out.println("Tu blok 1: Jest: " + counter);
    }

    public Incrementer(int ini){
        System.out.println("Incrementer(int): Bylo: " + counter);
        counter = ini;
        System.out.println("Incrementer(int): Jest: " + counter);
    }

    {
        System.out.println("Tu blok 2: Bylo: " + counter);
        counter = 100;
        System.out.println("Tu blok 2: Jest: " + counter);
    }

    public static void main(String[] argv){
        new Incrementer(1234);
    }
}
 */

/**
class Incrementer{
    private static int counter = 1;

    {
        System.out.println("Tu blok 1: Bylo: " + counter);
        counter = 10;
        System.out.println("Tu blok 1: Jest: " + counter);
    }

    public Incrementer(int ini){
        System.out.println("Incrementer(int): Bylo: " + counter);
        counter = ini;
        System.out.println("Incrementer(int): Jest: " + counter);
    }

    static{
        System.out.println("Tu blok statyczny: Bylo: " + counter);
        counter = 100;
        System.out.println("Tu blok statyczny: Jest: " + counter);
    }

    public static void main(String[] argv){
        System.out.println(">>>> Tu main: Jest: " + counter + " <<<<");
        new Incrementer(1234);
    }
}
 */

/**
class Incrementer {
    private static int counter = metoda();

    {
        System.out.println("Tu blok 1: Bylo         : " + counter);
        counter = 10;
    }

    public Incrementer(int ini) {
        System.out.println("Incrementer(int): Bylo  : " + counter);
        counter = ini;
    }

    static {
        System.out.println("Tu blok statyczny: Bylo : " + counter);
        counter = 100;
    }

    public static int metoda() {
        System.out.println("Tu metoda statyczna: Bylo : " + counter);
        return counter + 2;
    }

    public static void main(String[] argv) {
        System.out.println(">>>> Tu main: Jest      : " + counter + " <<<<");
        new Incrementer(1234);
        System.out.println(">>>> Tu main: Na koniec : " + counter + " <<<<");
    }
}
 */

/**
class Punkt{
    public Punkt(String nazwa, int... polozenie){
        System.out.println("Punkt " + nazwa + " jest w " + polozenie.length + " wymiarowej przestrzeni");
    }

    public static void main(String[] argv){
        new Punkt("2D", 1, 2);
        new Punkt("3D", 1, 2, 3);
        new Punkt("4D", 1, 2, 3, 4);
    }
}
 */

/**
class Zmieniacz{
    public static void main(String[] argv){
        int k = 0;
        System.out.println("Przed wywołaniem metody zmiana() k = " + k);
        zmiana(k);
        System.out.println("a po k " + k);
    }

    static void zmiana(int i){
        i++;
    }
}
 */

/**
class Pudelko{
    public int k;

    public void zmiana(){
        Zmieniacz.zmiana(this);
    }
}

class Zmieniacz{
    public static void main(String[] argv){
        Pudelko box = new Pudelko();
        System.out.println("Przed wywołaniem metody zmiana() k = " + box.k);
        zmiana(box);
        System.out.println("a po k = " + box.k);
    }

    static void zmiana(final Pudelko referencjaDoPudelka){
        referencjaDoPudelka.k++;
    }
}
*/

/**
class Pudelko{
    private int k;

    public Pudelko(int k){
        this.k = k;
    }

    public void inc(int k){
        this.k += k;
    }

    public void inc(){
        this.k++;
    }
 }
 */

/**
class PierwszyProgram{
    public static void main(String[] argy) {
        PierwszyProgram pp = new PierwszyProgram();
        String powitanie = pp + " Wita Java";
        System.out.println(powitanie);
        System.out.print("Moge i tak: ");
        System.out.println(pp);
    }
    public String toString() {
        return "Hello world ! Witaj Swiecie !";
    }
}
 */

/**
class PodstawienieVsWarunek{
    public static void main(String[] argv){
        int x, y;
        y = x = 10;

        if(y==11){
            //error: java: incompatible types: int cannot be converted to boolean
            System.out.println("W zmiennej y siedzi 11");
        }else{
            System.out.println("W zmiennej y NIE siedzi 11");
        }
    }
}
 */

/**
class Warunki{
    private static void test(int liczba){
        System.out.print("Test wywołano dla " + liczba + " i jest to ");
        if(liczba>0){
            System.out.println("liczba dodatnia");
        }else if(liczba<0){
            System.out.println("liczba ujemna");
        }else{
            System.out.println("zero");
        }
    }

    public static void main(String[] argy){
        test(-7);
        test(3);
        test(0);
    }
}
 */

/**
class Warunki{
    private static void test(int i){
        System.out.println("i = " + i);
        switch(i){
            default : System.out.println("Co najmniej 4");
            break;
            case 3 : System.out.println("Co najmniej 3");
            break;
            case 2 : System.out.println("Co najmniej 2");
            case 1 : System.out.println("Co najmniej 1");
        }
    }

    public static void main(String[] args){
        test(1);
        test(2);
        test(3);
        test(7);
    }
}
 */

/**
class Warunki{
    private static void test(int i){
        System.out.println("Start metody test (" + i + ")");

        outside:
        switch(i){
            default : {
                System.out.println("Co najmniej 4");
                switch(i){
                    case 4 : System.out.println("Dokładnie 4");
                    break;

                    case 5 : System.out.println("Dokładnie 5");
                        break;
                }
            }
            case 3 : System.out.println("Co najmniej 3");
                break;
            case 2 : System.out.println("Co najmniej 2");
            case 1 : System.out.println("Co najmniej 1");
        }
        System.out.println("Koniec metody test");
    }

    public static void main(String[] args){
        test(3);
        test(4);
        test(5);
        test(6);
    }
}
*/

/**
class Warunki{
    public static void main(String[] argv){
        test("Joanna");
        test("Andrzej");
        test("Pafnucy");
    }

    private static void test(String osoba){
        System.out.println("Kim jest " + osoba + "?");

        switch(osoba){
            case "Andrzej", "Marian", "Marek" :
                System.out.println("Kolega z pracy");
                break;

            case "Joanna" :
                System.out.println("Siostra");
                break;

            default :
                System.out.println("Nie wiem");

        }
    }
}
 */

/**
class Warunki{
    public static void main(String[] argv){
        test("Joanna");
        test("Andrzej");
        test("Pafnucy");
    }

    private static void test(String osoba){
        System.out.println("Kim jest " + osoba + "?");
        System.out.println(ktoTo(osoba));
    }

    private static String ktoTo(String osoba){
        return switch(osoba){
            case "Andrzej", "Marian", "Marek"
                -> "Kolega z pracy";

            case "Joanna"
                -> "Siostra";

            default -> "Nie wiem";
        };
    }
}
 */

/**
class Warunki{
    public static void main(String[] argv){
        test("Joanna");
        test("Andrzej");
        test("Pafnucy");
        test("Marek");
    }

    private static void test(String osoba){
        System.out.println("Kim jest " + osoba + "?");
        System.out.println(ktoTo(osoba));
    }

    private static String ktoTo(String osoba){
        return switch(osoba){
            case "Andrzej", "Marian", "Marek"
                    -> {
                System.out.println("UWAGA");
                yield "Kolega z pracy";
            }

            case "Joanna"
                    -> "Siostra";

            default -> "Nie wiem";
        };
    }
}
 */

/**
class OperatorWarunkowy{
    public static void main(String[] argv){
        test(-5);
        test(0);
        test(5);
    }

    private static void test(int i){
        System.out.println("Start metody test (" + i + ")");
        System.out.println("Dostarczona liczba całkowita jest: " +
                ((i>0) ? "nieujemna" : "ujemna"));

        if(i>=0){
            System.out.println("Dokładniej to jest ona " +
                    ((i==0) ? "równa zeru" : "dodatnia"));
        }
    }
}
 */

/**
class While{
    public static void whileTest(boolean test){
        int licznikBezpieczenstwa = 0;
        while(test){
            licznikBezpieczenstwa++;
            System.out.println("Wykonuje obieg nr. " + licznikBezpieczenstwa);

            if(licznikBezpieczenstwa > 4) return;
        }
    }

    public static void main(String[] argv){
        whileTest(false);
        whileTest(true);
    }
}
 */

/**
class DoWhile{
    public static void doWhileTest(boolean test){
        int licznikBezpieczenstwa = 0;
        do{
            licznikBezpieczenstwa++;
            System.out.println("Wykonuje obieg nr. " + licznikBezpieczenstwa);

            if(licznikBezpieczenstwa > 4) return;
        }while(test);
    }

    public static void main(String[] argv){
        doWhileTest(false);
        doWhileTest(true);
    }
}
 */

/**
class For{
    public static void main(String[] argv){
        int k=0, s=0, t=0;
        for(int i=0, sum=2; k<15; t++, s+=2){
            System.out.print("i = " + i + " sum = " + sum);
            System.out.print(" k = " + k);
            System.out.println(" t = " + t + " s = " + s);
            k=t+s+sum;
        }

        for(int i=0; i<5; i++){
            System.out.println("The Never Ending Story...");
        }
    }
}
 */

/**
class Label{
    public static void main(String[] argv){
        for (int j = 0; j < 11; j += 10)
            for (int i = 0; i < 123456; i++) {
                System.out.println("Start j = " + j + " i = " + i);
                if (i > 1) break;
                if (i > 0) continue;
                System.out.println("Stop  j = " + j + " i = " + i);
            }

        System.out.println("Continue z etykieta");

        label:
        for (int j = 0; j < 11; j += 10)
            for (int i = 0; i < 123456; i++) {
                System.out.println("Start j = " + j + " i = " + i);
                if (i > 0) continue label;
                System.out.println("Stop  j = " + j + " i = " + i);
            }

        System.out.println("Break z etykieta");

        label:
        for (int j = 0; j < 11; j += 10)
            for (int i = 0; i < 123456; i++) {
                System.out.println("Start j = " + j + " i = " + i);
                if (i > 0) break label;
                System.out.println("Stop  j = " + j + " i = " + i);
            }
    }
}
 */

/**
class Punkt{
    public Punkt(String nazwa, int... polozenie){
        System.out.println("Punkt " + nazwa + " jest w " + polozenie.length + " wymiarowej przestrzeni");
        System.out.print(" pozycja: ");
        for(int wsp : polozenie){
            System.out.print(" " + wsp);
        }
        System.out.println();
    }

    public static void main(String[] argv){
        new Punkt("2D", 1, 2);
        new Punkt("3D", 1, 2, 3);
        new Punkt("4D", 1, 2, 3, 4);
    }
}
 */

/**
class Punkt2D {
    public double x;
    public double y;

    public Punkt2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "Punkt2D( " + x + ", " + y + " )";
    }
}

class Start {
    public static void main(String[] argv) {
        Punkt2D[] kwadrat = new Punkt2D[4];

        kwadrat[0] = new Punkt2D(0, 0);
        kwadrat[1] = new Punkt2D(0, 1);
        kwadrat[2] = new Punkt2D(1, 0);
        kwadrat[3] = new Punkt2D(1, 1);

        for (Punkt2D p : kwadrat)
            System.out.println(p);
    }
}
 */

/**
class Start {
    public static void main(String[] argv) {
        double[] dt = { 111.1, 222.2, 333.3 };
        int[] it = { 1, 2, 3 };
        show(show(dt));
        show(null);
        // show(it); show(double[]) in Start cannot be applied to (int[])
        //show(new double [] {11.1, 22.2});
    }

    private static double[] show(double[] dv) {
        if (dv == null) {
            System.out.println("Nic nie przeslano");
            return null;
        }
        System.out.println("Zmienna tablicowa dv zawiera:");
        for (double d : dv)
            System.out.print(" " + d);
        System.out.println();
        return dv;
    }
}
*/

/**
class Start{
    public static void main(String[] argv){
        double [][] dt2x3 = {{1.0, 2.0, 3.0}, {11.1, 22.2, 33.3}};
        double [][][] dt4x2x3 = {dt2x3, dt2x3, dt2x3, dt2x3};
        show2(dt2x3);
        show3(dt4x2x3);
    }

    public static void show2(double [][] dv){
        System.out.println("dv.length = " + dv.length);
        System.out.println("dv[0].length = " + dv[0].length);
    }

    public static void show3(double [][][] dv){
        System.out.println("dv.length = " + dv.length);
        System.out.println("dv[0].length = " + dv[0].length);
        System.out.println("dv[0][0].length = " + dv[0][0].length);
    }
}
 */

/**
class Start {
    public static void main(String[] argv) {
        double[][] dt3 = new double[3][];
        dt3[0] = new double[10];
        dt3[1] = new double[0];  // tablica o rozmiarze 0
        dt3[2] = new double[100];
        show(dt3);
    }

    private static void show(double[][] dv) {
        System.out.println("dv.length = " + dv.length);
        for (int dim = 0; dim < dv.length; dim++) {
            System.out.println("d[" + dim + "].length = " + dv[dim].length);
        }
    }
}
 */

/**
class Operacje {
    private static final int LENGTH = 10;
    private static final String ZEROS = "0".repeat(LENGTH);

    private static int calc(int v1, int v2, String op) {
        return switch (op) {
            case "&" -> v1 & v2;   // AND bitowy
            case "|" -> v1 | v2;   // OR bitowy
            case "^" -> v1 ^ v2;   // XOR bitowy
            default -> 0;          // aby uspokoić kompilator
        };
    }

    private static String intAsBin(int value) {
        return dodajZera(Integer.toBinaryString(value));
    }

    private static String dodajZera(String bin) {
        return ZEROS.substring(0, (LENGTH - bin.length())) + bin;
    }

    public static void main(String[] args) {
        show(0b11001100, 0b00001111, "&");
        show(0b11001100, 0b00001111, "|");
        show(0b11001100, 0b00001111, "^");
    }

    private static void show(int v1, int v2, String op) {
        int wynikRachunku = calc(v1, v2, op);
        String v1s = intAsBin(v1);
        String v2s = intAsBin(v2);
        String wynikBin = intAsBin(wynikRachunku);

        System.out.println("    " + v1s);
        System.out.println("    " + v2s);
        System.out.println("    " + "-".repeat(LENGTH));
        System.out.println(" " + op + " " + wynikBin);
        System.out.println();
    }
}
*/

/**
import java.util.*;
class Wprost{
    public static void main(String[] args){
        List<Integer> lista1 = new ArrayList<Integer>();
        List<Integer> lista2 = new LinkedList<>();
        dodajCos(lista1); dodajCos(lista2);
        lista2.add(10);
        inspekcja(lista1);
        inspekcja(lista2);
    }

    private static void dodajCos(List<Integer> kolekcja){
        kolekcja.add(21);
        kolekcja.add(12);
    }

    private static void inspekcja(List<Integer> kolekcja){
        System.out.println("elementów  : " + kolekcja.size());
        System.out.println("zawiera    : " + kolekcja);
        System.out.println("zawiera 10 : " + kolekcja.contains(10));
    }
}
 */

/**
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

import java.util.*;
class Kolekcje{
    public static void main(String[] args){
        Collection<Integer> lista = new ArrayList<>();
        Set<Integer> zbior = new HashSet<>();
        dodajCos(lista);
        dodajCos(zbior);
        zbior.add(10);
        inspekcja(lista);
        inspekcja(zbior);
    }

    private static void dodajCos(Collection<Integer> kolekcja){
        kolekcja.add(21);
        kolekcja.add(12);
    }

    private static void inspekcja(Collection<Integer> kolekcja){
        System.out.println("elementów  : " + kolekcja.size());
        System.out.println("zawiera    : " + kolekcja);
        System.out.println("zawiera 10 : " + kolekcja.contains(10));
    }
}
*/

/**
class Iterator{
    public static void main(String[] args){
        Collection<Integer> lista = new ArrayList<>();
        Collection<Integer> zbior = new HashSet<>();
        dodajCos(lista);
        dodajCos(zbior);
        zbior.add(10);
        inspekcja(lista);
        inspekcja(zbior);
    }

    private static void dodajCos(Collection<Integer> kolekcja){
        kolekcja.add(21);
        kolekcja.add(12);
    }

    private static void inspekcja(Collection<Integer> kolekcja){
        int element = 0;
        for(int e : kolekcja){
            System.out.println("Element nr " + element + " to " + e);
            element++;
        }
        System.out.println("Znaleziono " + element + " elementy");
    }
}
 */

/**
import java.util.*;
class Kolejki {
    public static void main(String[] args) {
        LinkedList<String> lista = new LinkedList<>();
        queueTest(lista);
        dequeTest(lista);
    }

    private static void queueTest(Queue<String> q) {
        q.offer("Przystanek Czerwone Maki");
        q.offer("Przystanek Grota-Roweckiego");
        q.offer("Przystanek Koszykarska");
        System.out.println(q.poll());
        System.out.println(q.poll());
    }

    private static void dequeTest(Deque<String> q) {
        q.addFirst("Przystanek Czerwone Maki");
        q.addFirst("Przystanek Grota-Roweckiego");
        q.addLast("Przystanek Koszykarska");
        System.out.println(q.pollFirst());
        System.out.println(q.pollLast());
    }
}
*/

/**
import java.util.*;
class Stos {
    private final Deque<String> kolejka = new LinkedList<>();

    public void push(String e) {
        kolejka.addFirst(e);
    }

    public String pop() { // usuwa element
        return kolejka.removeFirst();
    }

    public String peek() { // nie usuwa elementu
        return kolejka.getFirst();
    }

    public static void main(String[] args) {
        Stos s = new Stos();
        s.push("Pierwszy !");
        s.push("Drugi");
        s.push("Trzeci");

        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.pop());
    }
}
*/

/**
import java.util.*;
class Mapa{
    public static void main(String[] args){
        Map<Integer, String> id2Nazwisko = new HashMap<>();
        id2Nazwisko.put(123456, "Kowalski");
        id2Nazwisko.put(123457, "Nowak");
        id2Nazwisko.put(123458, "Igrekowski");
        id2Nazwisko.put(123458, "Iksinski");

        for(Map.Entry<Integer, String> el : id2Nazwisko.entrySet()){
            System.out.println(el.getKey() + " -> " + el.getValue());
        }
        System.out.println(id2Nazwisko.get(123458));
    }
}
 */

/**
import java.util.*;
class Szybkosc {

    private final static int TESTS = 5_000_000;
    private final static Random rnd = new Random();
    private final static int data[] = new int[TESTS];
    private final static int index[] = new int[TESTS];
    private final List<Integer> kolekcjaDoPrzetestowania;

    static {
        for (int i = 0; i < TESTS; i++) {
            data[i] = rnd.nextInt();
            index[i] = rnd.nextInt(TESTS);
        }
    }

    private Szybkosc(List<Integer> kolekcjaDoPrzetestowania) {
        this.kolekcjaDoPrzetestowania = kolekcjaDoPrzetestowania;
        testDodawania();
        testOdczytu();
    }

    private void testDodawania() {
        long start = System.currentTimeMillis();

        for (int i = 0; i < TESTS; i++) {
            kolekcjaDoPrzetestowania.add(data[i]);
        }

        long czasPracy = System.currentTimeMillis() - start;
        System.out.println("Test dodawania. Dodano " + TESTS +
                " danych w czasie " + czasPracy + " ms");
    }

    private void testOdczytu() {
        long start = System.currentTimeMillis();

        for (int i = 0; i < TESTS; i++) {
            kolekcjaDoPrzetestowania.get(index[i]);
        }

        long czasPracy = System.currentTimeMillis() - start;
        System.out.println("Test pobierania. Odczytano " + TESTS +
                " danych w czasie " + czasPracy + " ms");
    }

    public static void main(String[] args){
        System.out.println("Test ArrayList");
        new Szybkosc(new ArrayList<>());

        System.out.println("Test ArrayList + podany rozmiar");
        new Szybkosc(new ArrayList<>(TESTS));

        System.out.println("Test LinkedList");
        new Szybkosc(new LinkedList<>());
    }
}
*/

/**
class PierwszyProgram{
    public void sayHello(){
        String napisEN = new String("Hello world!");
        String napisPL = "Witaj swiecie!";
        System.out.println(napisEN + " " + napisPL);
    }

    public static void main(String[] args){
        PierwszyProgram pp = new PierwszyProgram();
        pp.sayHello();

        String napis = """
                 Ala
                ma kota
                i psa
                .
                """;
        System.out.println();
        System.out.println(napis);
    }
}
 */

/**
class SzybkieLaczenieLancuchow{
    public static void main(String[] args){
        StringBuilder builder = new StringBuilder();
        String chunk = "Fragment";

        for(int i=0; i<1000; i++){
            builder.append(" ");
            builder.append(i+1 + ". " + chunk + "\n");
        }

        String gotowyNapis = builder.toString();
        System.out.println(gotowyNapis);
        String napis = ">";

        for(int i = 0; i<10; i++){
            napis += " " + i;
        }
        System.out.println(napis);
    }
}
 */

/**
import java.util.Scanner;
class Skan{
    private static final Scanner input = new Scanner(System.in);

    public static void main(String[] args){
        System.out.println("Podaj podatek VAT w procentach> ");

        if(input.hasNextDouble()){
            double vat = input.nextDouble();
            input.nextLine();

            double cenaNetto = 123;
            double podatek = cenaNetto*vat/100.0;

            System.out.println("Dla ceny netto " + cenaNetto + " zapłacimy " + podatek + " podatku");
        }else{
            System.err.println("Danych nie można prawidłowo zinterpretować");
        }

        System.out.println("Podaj imie> ");
        String imie = input.nextLine();
        System.out.println("Który to rok> ");
        int rok = input.nextInt();
        System.out.println("Podaj temperaturę> ");
        double temperatura = input.nextDouble();
        System.out.println("Witam Cię " + imie + " w roku " + rok);
        System.out.println("Temperatura: " + temperatura);

    }
}
 */

/**
import java.util.Scanner;
class Skan{
    private static final Scanner skaner = new Scanner(System.in);
    public static void main(String[] args){
        final int BUFOR = 10;
        String[] napisy = new String[BUFOR];
        int wczytano = 0;
        String tmp;

        while(true){
            tmp = skaner.next();
            System.out.println("Odebrano: " + tmp + "");
            if(tmp.equals("exit")) break;
            napisy[wczytano++] = tmp;
            if(wczytano == BUFOR) break;
        }
        System.out.println("Wczytano: " + wczytano + " danych: ");
        System.out.println("Oto one: " + String.join("; ", napisy));
    }
}
 */

/**
import java.io.Console;
import java.util.Arrays;
class ReadPassword{
    public static void main(String[] args){
        final Console konsola = System.console();

        if (konsola == null) {
            System.err.println("Brak dostępu do konsoli!");
            System.exit(1);
        }

        System.out.print("Podaj username: ");
        String username = konsola.readLine();
        System.out.print("Podaj password: ");
        char[] password = konsola.readPassword();

        System.out.println("\nOdczytano " + username + " / " + Arrays.toString(password));
    }
}
*/

/**
class Tabela{
    public static void main(String[] args){
        final double VAT  = 1.23;
        final double KROK = 2.34;
        final double MAX  = 2430;
        final String NLINE = "\n";
        final String TAB   = "\t";
        StringBuffer sb = new StringBuffer();
        for (double cena = 10.1; cena < MAX; cena *= KROK){
            sb.append(String.format("%8.2f", cena));
            sb.append(TAB);
            sb.append(String.format("%08.2f", cena * VAT));
            sb.append(NLINE);
        }
        System.out.println(sb.toString());
    }
}
*/

/**
import java.util.*;
class Formater{
    public static void main(String[] args){
        final String FORMAT = "%010.2f";
        final Locale LOKALIZACJA = Locale.CHINESE;
        final double liczba = 123.456;

        System.out.println(new Formatter().format(LOKALIZACJA, FORMAT, liczba));
    }
}
*/

/**
class Potomna extends Bazowa{
    public static void main(String[] args){
        Potomna.poleStatyczne+=10;
        Potomna.metodaStatyczna();

        Potomna refDoPotomnej = new Potomna();
        refDoPotomnej.poleNiestatyczne++;
        refDoPotomnej.metodaNiestatyczna();

        System.out.println("poleNiestatyczne " + refDoPotomnej.poleNiestatyczne);
        System.out.println("poleStatyczne " + refDoPotomnej.poleStatyczne);
    }
}

class Bazowa{
    static int poleStatyczne = 10;
    int poleNiestatyczne = 11;

    static void metodaStatyczna(){
        System.out.println("Oto metodaStatyczna");
    }

    void metodaNiestatyczna(){
        System.out.println("Oto metodaNiestatyczna");
    }
}
*/

/**
class Pierogi {
    public static void main(String[] args) {
        mamOchoteNaPierogi(new Rodzic());
        mamOchoteNaPierogi(new Potomek());
    }

    private static void mamOchoteNaPierogi(Rodzic ref) {
        System.out.println("Co powiesz? ");
        ref.umiemRobicPierogi();
    }
}

class Rodzic {
    public void umiemRobicPierogi() {
        System.out.println("To ja Rodzic. Wiem jak zrobic pierogi");
    }
}

class Potomek extends Rodzic {
    public void umiemRobicPierogi() {
        System.out.println("To ja Potomek. Umiem robic lepsze pierogi!");
    }
}
 */

/**
class Czlowiek {
    protected String dataUrodzenia, nazwisko;

    public Czlowiek(String du, String n) {
        System.out.println("Czlowiek(String du, String n)");
        dataUrodzenia = du;
        nazwisko = n;
    }
}

class Pracownik extends Czlowiek {
    private String stanowisko;

    public Pracownik(String du, String n, String st) {
        super(du, n); // Inaczej powoduje blad kompilacji:
        // cannot find symbol
        // symbol : constructor Czlowiek()
        stanowisko = st;
    }

    public String toString() {
        return "Nazwisko: " + nazwisko + "; Stanowisko pracy " + stanowisko;
    }
}

class Start {
    public static void main(String[] argv) {
        System.out.println(new Pracownik("1999-09-09", "Kowalski", "starszy kowal"));
    }
}
*/

/**
class KlasaBazowa {
    public String napis = "tu bazowa";
    public String test() { return "tu bazowa"; }
}

class KlasaPochodna extends KlasaBazowa {
    public String napis = "tu pochodna";
    public String test() { return "tu pochodna"; }
}

class Start {
    public static void main(String[] argv) {
        KlasaBazowa bazowa = new KlasaBazowa();
        KlasaPochodna pochodna = new KlasaPochodna();

        System.out.println("Pole> " + bazowa.napis);
        System.out.println("Pole> " + pochodna.napis);
        System.out.println("Metoda> " + bazowa.test());
        System.out.println("Metoda> " + pochodna.test());

        bazowa = pochodna;

        System.out.println("Pole> " + bazowa.napis);
        System.out.println("Pole> " + pochodna.napis);
        System.out.println("Metoda> " + bazowa.test());
        System.out.println("Metoda> " + pochodna.test());
    }
}
 */

/**
class Main {
    public static void main(String[] args) {
        Obliczenia o = new Kalkulator();
        o.setA(1);
        o.reset();
        o.setB(2);
        System.out.println( o.calcAApB() );
    }
}

interface Obliczenia {
    void setA( int a );
    void setB( int b );
    int calcAApB();

    default void reset() {
        setA(0);
        setB(0);
    }
    public static int aapb( int a, int b ) {
        return a*a + b;
    }
}

class Kalkulator implements Obliczenia {
    private int a;
    private int b;

    public void setA( int a ) {
        this.a = a;
    }
    public void setB( int b ) {
        this.b = b;
    }
    public int calcAApB( ) {
        return Obliczenia.aapb( a, b );
    }
}
 */

/**
class Start {
    public static void main(String[] argv) {
        KlasaPochodna pochodna = new KlasaPochodna();
        pochodna.show();
    }
}

class KlasaPochodna extends KlasaBazowa {
    public String test = "tu pochodna";
    public String get() {
        return test;
    }

    public void show() {
        System.out.println(this.test);
        System.out.println(this.get());
        System.out.println(super.test);
        System.out.println(super.get());
        System.out.println(((KlasaBazowa)this).get());
    }
}

class KlasaBazowa {
    public String test = "tu bazowa";
    public String get() { return test; }
}
 */

/**
class Start {
    public static void glaskanieKota(Object cos) {
        if (cos instanceof Kot kot) {
            System.out.println("Glaszczemy kota a on na to:");
            System.out.println(kot.mruczenie());
        }else if(cos instanceof Tygrys kot){
            System.out.println("Glaszczemy dużego kota a on na to:");
            System.out.println(kot.mruczenie());
        }
        else {
            System.out.println("Oj to jednak nie jest kot...");
        }


        switch (cos){
            case null -> {}
            case Kot kot -> {
                System.out.println("Glaszczemy kota a on na to:");
                System.out.println(kot.mruczenie());
            }

            case Tygrys kot when kot.mruczenie().contains("RRR") -> {
                System.out.println("Glaszczemy dużego kota a on na to:");
                System.out.println(kot.mruczenie());
            }

            default -> {
                System.out.println("Oj to jednak nie jest kot...");
            }
        }
    }

    public static void main(String[] argv) {
        glaskanieKota(new Jez());
        glaskanieKota(new Kot());
        glaskanieKota(new Tygrys());
    }
}

class Kot {
    public String mruczenie() { return "Mrrrrrrr...."; }
}

class Jez {
    public String mruczenie() { return "Chyba zartujesz..."; }
}

class Tygrys{
    public String mruczenie() { return "MRRRRRRRRR...."; }
}
*/

/**
class Main{
    public static void main(String[] argv){
        Box box = new Box();
        System.out.println(box);
        magik(box);
        System.out.println(box);
    }
    private static void magik(Box box){
        box.put(new Królik());
    }
}

class Box{
    private Object ref;
    public void put(Object sth){
        ref = sth;
    }
    public String toString(){
        return "[" + ( ref == null ? " " : ref) + "]";
    }
}

class Królik{
    public String toString(){
        return "\uD83D\uDC07";
    }
}
*/

/**
class Start {
    static void test(Modifiable m) {
        m.set(1, 12);
        m.set(2, 23);
        System.out.println("[1]=" + m.get(1) + " [2]=" + m.get(2));
    }

    public static void main(String[] argv) {
        test(new Box(3));
    }
}

interface Modifiable {
    int get(int i);
    void set(int i, int v);
}

class Box implements Modifiable {
    private int[] tbl;

    public int get(int i) { return tbl[i]; }
    public void set(int i, int v) { tbl[i] = v; }

    Box(int size) {
        tbl = new int[size];
    }
}
*/

/**
class Start{
    public static void main(String[] argv){
        Controllable sec = new Secutity();
        sec.setMode(Controllable.STRICT);
    }
}

interface Controllable{
    int STRICT = 0;
    int RELAXED = 1;
    void setMode(int i);
}

class Secutity implements Controllable{
    int level;

    public void setMode(int i){
        level = i;
    }
}
*/

/**
class Start implements WaznyInterface {
    final private WaznyInterface wi = new KlasaImplementujaca();

    public void showBlaBlaBla() {
        wi.showBlaBlaBla();
    }

    public static void main(String[] argv) {
        (new Start()).showBlaBlaBla();
    }
}

interface WaznyInterface {
    void showBlaBlaBla();
}

class KlasaImplementujaca implements WaznyInterface {
    public void showBlaBlaBla() {
        System.out.println("Bla Bla Bla..");
    }
}
*/

/**
interface Secure {
    public void cokolwiek();
}

class KlasaImplementujaca implements Secure {
    public void cokolwiek() {
        System.out.println("Bla Bla Bla..");
    }
}

class Start {
    public static boolean testSecurity(Object o) {
        if (o instanceof Secure) return true;
        else return false;
    }

    public static void main(String[] argv) {
        System.out.println(
                testSecurity(new KlasaImplementujaca()) ? "TAK" : "NIE");
        System.out.println(testSecurity("snkasjska") ? "TAK" : "NIE");
    }
}
*/

/**
record Box(int width, int length, int height){
    public Box(){
        this(1, 1, 1);
    }

    public Box{
        width = Math.abs(width);
        length = Math.abs(length);
        height = Math.abs(height);
    }

    public int volume(){
        return width*length*height;
    }

    public static Box multiply (Box box, int r){
        return new Box(box.width*r, box.length*r, box.height*r);
    }

    public static void main(String[] argv){
        Box unit = new Box();
        Box inpostA = new Box(8, 38, 64);
        Box unit_2 = Box.multiply(unit, 2);

        System.out.println(unit_2 + " volume " + unit_2.volume());
        System.out.println(inpostA + " volume " + inpostA.volume());
    }
}
*/

/**
class Main{
    public static void main(String[] argv){
        Auto auto = new Auto();
        auto.uruchom(new Klucz());
        auto.uruchom(new Wytrych());
    }
}

class Auto{
    private final String KOD = "11-11";
    public void uruchom(Klucz klucz){
        if(klucz.pasuje(KOD)) System.out.println("Brum");
        else System.out.println("PiPi");
    }
}

class Klucz{
    private final String KOD = "1234";
    public boolean pasuje(String kod){
        return KOD.equals(kod);
    }
}

class Wytrych extends Klucz{
    public boolean pasuje (String kod){
        return true;
    }
}
*/

/**
class Start{
    public static void main(String[] argv){
        test(Kolory.BIALY);
        test(Kolory.NIEBIESKI);

        Kolory k = Kolory.CZERWONY;
        System.out.println("Liczba kolorów: " + Kolory.liczbaZdefiniowanychKolorow());
        System.out.println(k);
    }

    private static void test(Kolory k){
        System.out.println(k.name() + " -> " + k);
    }
}

enum Kolory{
    CZARNY("000000"), CZERWONY("ff0000"), ZIELONY("00ff00"), BIALY("ffffff"), NIEBIESKI("0000ff");

    private final static String prefix = "0x";
    private final String rgb;

    Kolory(String n){
        rgb = prefix + n;
    }

    public String toString(){
        return rgb;
    }

    public static int liczbaZdefiniowanychKolorow(){
        return Kolory.values().length;
    }
}
*/

/**
class Main{
    public static void main(String[] argv) {
        test(Shape.TRIANGLE);
        test(Shape.RECTANGLE);
        test(Shape.ELLIPSE);
    }
    private static void test(Shape s){
        System.out.println("Pole dla " + s.name() + " to: " + s.area(2,2));
    }
}

enum Shape{
    TRIANGLE{
        public double area(int x, int y){
            return x*y/2.0;
        }
    },
    RECTANGLE{
        public double area(int x, int y){
            return x*y;
        }
    },
    ELLIPSE{
        public double area(int x, int y){
            return Math.PI*x*y/4.0;
        }
    };
    public abstract double area(int x, int y);
}
*/

/**
class Start {
    public static void main(String[] argv) {
        Zewnetrzna zew = new Zewnetrzna();
        Zewnetrzna.Wewnetrzna zw = new Zewnetrzna.Wewnetrzna();
        System.out.println("I = " + zw.getI());
        System.out.println("J = " + zew.getJ());
    }
}

class Zewnetrzna {
    private static int i = 10;
    Wewnetrzna wew = new Wewnetrzna();

    public int getJ() {
        return wew.j;  // nie ma bezposredniego dostepu
    }

    static class Wewnetrzna {
        private static int j = 100;

        public int getI() {
            return i;
        }
    }
}
*/

/**
class Start{
    public static void main(String[] argv){
        Pudelko p = new Pudelko();
    }
}

class Pudelko{
    int dlugosc = 50;
    LCD lcd = new LCD();

    class LCD extends Box {
        public LCD() {
            System.out.println("Rozmiar wyswietlacza to " + (Pudelko.this.dlugosc / 2));
        }
    }
}

class Box{
    int dlugosc = 100;
}
*/

/**
class Zewnetrzna {
    private static int i = 123;

    public static void main(String[] argv) {
        Zewnetrzna z = new Zewnetrzna();
        Zewnetrzna.Wewnetrzna zw = z.new Wewnetrzna();
        Zewnetrzna.Zagniezdzona zz = new Zewnetrzna.Zagniezdzona();

        System.out.println("wz.getI() = " + zw.getI());
        System.out.println("zz.getI() = " + zz.getI());
    }

    static class Zagniezdzona {
        private static int j = 100;

        public int getI() {
            j++;
            return j + i;
        }
    }

    class Wewnetrzna {
        private static int j = 100;

        public int getI() {
            j++;
            return j + i;
        }
    }
}
*/

/**
class Start{
    public static void main(String[] argv){
        System.out.println("" + (new Pudelko()).lcd);
    }
}
class Pudelko extends Box{
    private int i = 512;
    public LCD lcd = new LCD();

    class LCD{
        public String toString(){
            return "Wyswietl: " + Pudelko.super.i;
        }
    }
}
class Box{
    protected int i = 1024;
}
*/

/**
class Start {
    public static void main(String[] argv) {
        System.out.println("" + (new Pudelko()).lcd.ps);
    }
}

class Pudelko {
    private int i = 512;
    public LCD lcd = new LCD();

    class LCD {
        private int i = 777;
        public PowerSaving ps = new PowerSaving();

        class PowerSaving {
            public String toString() {
                return "Wyswietl: " + Pudelko.this.i + " tryb pracy " + LCD.this.i;
            }
        }
    }
}
 */

/**
class Start {
    public static void main(String[] argv) {
        Pudelko p = new Pudelko();
    }
}

class Pudelko {

    void show() {
        System.out.println("Jestem Pudelko");
    }

    void show(int i) {
        System.out.println("Jestem Pudelko, dlugosc " + i);
    }

    LCD lcd = new LCD();

    class LCD extends Box {
        public LCD() {
            show();
            // show(5); // show() in Box cannot be applied to (int)
            Pudelko.this.show(5);
        }
    }
}

class Box {
    void show() {
        System.out.println("Jestem BOX");
    }
}
*/

/**
class Start{
    static String separator = " : ";
    static Gadacz mojGadacz;

    static {
        class NowyGadacz extends Gadacz{
            String nazwa = "Jestem gadacz";
            void mow(String tekst){
                System.out.println(nazwa + separator + tekst);
            }
        }
        mojGadacz = new NowyGadacz();
    }
    public static void main(String[] argv){
        mojGadacz.mow("-s-s-s-s-s-s-");
    }
}

abstract class Gadacz{
    abstract void mow(String tekst);
}
*/

/**
class Start implements PobieranieDanych {
    public Dane get() {
        return (new DefaultImplementation()).get();
    }

    public static void main(String[] argv) {
        System.out.println("Pobrano: " + (new Start()).get().i);
    }
}

interface PobieranieDanych {
    Dane get();

    class Dane {  // format pobieranych danych
        public int i;
    }

    class DefaultImplementation implements PobieranieDanych {
        public Dane get() {
            Dane d = new Dane();
            d.i = 1;  // wartosc domyslna
            return d;
        }
    }
}
*/

/**
class Sender implements WymianaDanych {
    void send(int i) {
        stalaReferencja.i = i;
    }
}

class Receiver implements WymianaDanych {
    int receive() {
        return stalaReferencja.i;
    }
}

interface WymianaDanych {
    Dane stalaReferencja = new Dane();

    class Dane { // format pobieranych danych
        public int i;
    }
}

class Start {
    public static void main(String[] argv) {
        (new Sender()).send(12345);
        System.out.println("Odebrano : " + (new Receiver()).receive());
    }
}
*/

/**
class Main{
    public static void main(String[] args){
        System.out.println(Takzwane.Jajko.KOLUMBA);
    }
}

public class Takzwane{
    enum Jajko{
        KWADRATOWE, KURZE, KOLUMBA;
    }
}
*/

/**
class Start implements PobieranieDanych {
    public Dane get() {
        return (new DefaultImplementation()).get();
    }

    public static void main(String[] argv) {
        System.out.println("Pobrano: " + (new Start()).get().i);
    }
}

interface PobieranieDanych {
    Dane get();

    class Dane { // format pobieranych danych
        public int i;
    }

    class DefaultImplementation implements PobieranieDanych {
        public Dane get() {
            Dane d = new Dane();
            d.i = 1; // wartość domyślna
            return d;
        }
    }
}
 */

/**
class Start {
    public static void main(String[] argv) {
        PudelkoNaRozneRoznosci<String> pstr = new PudelkoNaRozneRoznosci<String>();
        PudelkoNaRozneRoznosci<Integer> pi = new PudelkoNaRozneRoznosci<Integer>();

        pstr.referencja = "Ala ma kota";
        pi.tablicaReferencji = new Integer[10];

        // pstr.referencja = new Integer(1111);
        // pstr.tablicaReferencji = new Float[10];
        // Błędy kompilacji: incompatible types

        System.out.println(pi);
    }
}

class PudelkoNaRozneRoznosci<E> {
    public E referencja;
    public E[] tablicaReferencji;

    @Override
    public String toString() {
        return "PudelkoNaRozneRoznosci{" + "referencja=" + referencja + ", tablicaReferencji=" + java.util.Arrays.toString(tablicaReferencji) + '}';
    }
}
*/

/**
import java.util.ArrayList;
import java.util.Random;

public class Deklaracje{
    public static void main(String[] argv){
        ArrayList<Integer> wprost = new ArrayList<Integer>();
        ArrayList<Integer> odJava7 = new ArrayList<>();
        var odJava10Object = new ArrayList<>();
        var odJava10Integer = new ArrayList<Integer>();

        odJava10Object.add(1);
        odJava10Object.add("ala");
        odJava10Object.add(new Random());

        System.out.println(odJava10Object);
    }
}
*/

/**
class Start {
    public static void main(String[] argv) {
        PudelkoNaRozneRoznosci<String> pstr = new PudelkoNaRozneRoznosci<String>();
        PudelkoNaRozneRoznosci<Integer> raw = new PudelkoNaRozneRoznosci<Integer>();

        //raw = pstr;
        pstr = raw;
        raw.referencja = 123;
        //java: incompatible types: PudelkoNaRozneRoznosci<java.lang.String>
        //cannot be converted to PudelkoNaRozneRoznosci<java.lang.Integer>
    }
}

class PudelkoNaRozneRoznosci<E> {
    public E referencja;
    //public E[] tablicaReferencji;
}
 */

/**
interface Mierzalny{
    int miara();
}

interface Gadatliwy{
    void mow();
}

class Cegla implements Mierzalny, Gadatliwy{
    public int miara(){
        return 250;
    }
    public void mow(){
        System.out.println("Jestem typową cegłą, mam 250mm długości");
    }
}

class Kubek implements Mierzalny, Gadatliwy{
    public int miara(){
        return 110;
    }
    public void mow(){
        System.out.println("Jestem kubkiem, mam 110mm długości");
    }
}

class Ryba implements Mierzalny{
    public int miara(){
        return 550;
    }
}

class Komparator<E extends Mierzalny & Gadatliwy>{
    private E pole;
    public Komparator(E ref){
        pole = ref;
    }

    public void porownaj(Mierzalny ref){
        System.out.println("Obiekt własny    : " + pole);
        System.out.println("Obiekt przysłany : " + ref);

        if(pole.miara()>ref.miara()){
            System.out.println("Własny jest większy i mówi: ");
            pole.mow();
        }
    }
}

class Start{
    public static void main(String[] argv){
        Komparator<Cegla> kc = new Komparator<Cegla>(new Cegla());
        kc.porownaj(new Kubek());
    }
}
*/

/**
class BoxWithUndo<E>{
    static class Box<E>{
        public E tmp;
    }

    Box<E> value = new Box<E>();
    Box<E> backup = new Box<E>();
    Box<String> opis = new Box<String>();
}

class Start{
    public static void main(String[] argv){
        BoxWithUndo<Integer> bi = new BoxWithUndo<Integer>();

        bi.value.tmp = new Integer(5);
        bi.backup.tmp = bi.value.tmp;
        bi.opis.tmp = "Wartość początkowa to 5";
    }
}
 */

/**
class BoxWithUndo<E>{
    class Box{
        public E tmp;
    }

    class Opis<E>{
        public E tmp;
    }

    Box value = new Box();
    Box backup = new Box();
    Opis opis = new Opis();
}

class Start{
    public static void main(String[] argv){
        BoxWithUndo<Integer> bi = new BoxWithUndo<Integer>();

        bi.value.tmp = new Integer(5);
        bi.backup.tmp = bi.value.tmp;
        bi.opis.tmp = "Wartość początkowa to 5";

        System.out.println("Value: " + bi.value.tmp);
        System.out.println("Backup: " + bi.backup.tmp);
        System.out.println("Opis: " + bi.opis.tmp);
    }
}
*/

/**
class Box<E> {
    E value;
}

class Start {
    static void get(Box<? extends Number> b) {
        Number n = b.value;
    }

    static void set(Box<? super Integer> b) {
        b.value = new Integer(10);
    }

    public static void main(String[] argv) {
        Box<Integer> bint = new Box<Integer>();
        Box<Number> bnum = new Box<Number>();

        get(bint);
        set(bnum);
    }
}
*/

/**
class Start{
    public static <T> T loopback (T ref){
        return ref;
    }
    public <T> T nonStaticLoopback(T ref){
        return ref;
    }

    public static void main(String[] argv){
        String str1 = Start.<String>loopback("Ala ma kota");
        str1 = loopback("Ala ma kota");

        Start start = new Start();

        str1 = start.<String>nonStaticLoopback("Ala ma mysz");
        str1 = start.nonStaticLoopback("Ala ma mysz");
        Object o = start.nonStaticLoopback(new Integer(1));
    }
}
*/

/**
import java.util.*;
class Box<E>{
    E value;
}

public class Wildcard{
    static void processNumbers(List<? extends Number> list) {
        for (Number n : list) {  // ✅ Odczyt jako Number
            System.out.println(n.doubleValue());
        }
        // list.add(10);  // ❌ Nie można zapisywać
    }

    public static void main(String[] argv){
        //Box<?> pudelkoNaCos = new Box<String>();
        //Box<? extends String> pudelkoNaCosDoString = new Box<String>();
        //pudelkoNaCos.value = "Ala ma kota";
        //java: incompatible types: java.lang.String cannot be converted to capture#1 of ?
        //pudelkoNaCosDoString.value = "i psa";
        processNumbers(new ArrayList<Integer>());  // ✅ OK
        processNumbers(new ArrayList<Double>());   // ✅ OK
        processNumbers(new ArrayList<Float>());    // ✅ OK
        processNumbers(new ArrayList<Number>());   // ✅ OK
    }
}
 */

/**
public class Capture{
    public static void main(String[] argv){
        Pair<Integer> pair = new Pair<>(1, 2);
        swap(pair);
    }

    public static void swap(Pair<?> pair){
        swapHelper(pair);
    }

    public static <T> void swapHelper(Pair<?> pair){
        T tmp = pair.v1;
        pair.v1 = pair.v2;
        pair.v2 = tmp;
    }
}

class Pair<E>{
    E v1, v2;

    public Pair(E v1, E v2){
        this.v1 = v1;
        this.v2 = v2;
    }
}
 */

/**
class Start{
    public static void main(String[] argv){
        Integer[] ti = new Integer[10];
        Object[] to = new Object[10];

        to = new String[10];
        to[5] = new Float(10.0);
        //Exception in thread "main" java.lang.ArrayStoreException: java.lang.Float
        //	at Start.main(Priorytety.java:1985)
    }
}
 */

/**
interface Comparable<E>{
    boolean compare(E ref);
}

class Box implements Comparable<Box>{
    public boolean compare(Box ref){
        return true;
    }
}

class BoxExt extends Box implements Comparable<BoxExt>{
    public boolean compare(Box ref){
        return false;
    }
}

class Start{
    public static void main(String[] argv){
        Box bx = new BoxExt();
        System.out.println(bx.compare(new BoxExt()) ? "T" : "F");
        //java: Comparable cannot be inherited with different arguments: <BoxExt> and <Box>
    }
}
 */

/**
import java.io.*;
class Replika{
    public static void main(String[] argv) throws IOException{
        int c;
        try(InputStream rd = System.in){
            while((c = rd.read()) != -1){
                System.out.print((char) c);
            }
        }
    }
}
 */

/**
import java.io.*;
import java.util.stream.IntStream;
import java.util.zip.*;

public class SaveTxt {
    public static void main(String[] args) throws Exception {

        try (PrintWriter wrt = new PrintWriter(
                new OutputStreamWriter(        // char -> byte
                        new GZIPOutputStream(          // kompresja
                                new FileOutputStream("output"))))) { // plik

            IntStream.range(1, 100).forEach(i -> {    // for od 1 do 99
                try {
                    wrt.println("Ala ma kota po raz " + i);
                } catch (Exception e) {}
            });
        }

        String txt;
        try (BufferedReader reader = new BufferedReader(
                new InputStreamReader(        // byte -> char
                        new GZIPInputStream(          // dekompresja
                                new FileInputStream("output"))))) { // odczyt z pliku

            while ((txt = reader.readLine()) != null) {
                System.err.println(txt);
            }
        }
    }
}
 */

/**
import java.io.*;
import java.util.Random;
import java.util.stream.IntStream;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;
class WriteDouble{
    public static void main(String[] argv) throws Exception{
        Random rnd = new Random();

        try(DataOutputStream data = new DataOutputStream(new GZIPOutputStream(new FileOutputStream("doubles.gz")))){
            IntStream.range(0, 10000).forEach((i) -> {
                try{
                    data.writeDouble(rnd.nextDouble());
                }catch(IOException e) {}
            });
        }

        try(DataInputStream data = new DataInputStream(new GZIPInputStream(new FileInputStream("doubles.gz")))){
            double sum = 0.0;
            int count = 0;
            try{
                while(true){
                    sum += data.readDouble();
                    count++;
                }
            }catch(IOException e){
                System.out.println("Średnia z otczytanych danych to " + (sum/count));
            }
        }
    }
}
 */

/**
import java.io.*;
public class Undo {
    public static void main(String[] args) throws Exception {

        ByteArrayOutputStream streamO = new ByteArrayOutputStream();
        save(new Data(10, Math.PI), streamO);

        byte[] memory = streamO.toByteArray(); // w tej tablicy bajtów jest obiekt

        ByteArrayInputStream streamI = new ByteArrayInputStream(memory);
        Data data = (Data) restore(streamI);

        System.out.println(data);
    }

    private static void save(Serializable object, OutputStream stream) throws Exception {
        new ObjectOutputStream(stream).writeObject(object); // zapis
    }

    private static Object restore(InputStream stream) throws Exception {
        return new ObjectInputStream(stream).readObject(); // odzysk
    }
}

// obiekt tego rekordu zapiszemy w pamięci, a potem odtworzymy
record Data(int counter, double value) implements Serializable {}
 */

/**
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
class Loader {
    public static void main(String[] args) throws Exception {
        Class.forName("Testowa", true, new MyClassLoader());
    }
}

class MyClassLoader extends ClassLoader {

    protected Class<?> findClass(String name) throws ClassNotFoundException {
        System.out.println("Ladowanie klasy " + name);
        byte[] bCode = null;
        try {
            bCode = Files.readAllBytes(Paths.get(name + ".class"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return defineClass(name, bCode, 0, bCode.length);
    }

    public Class<?> loadClass(String name) throws ClassNotFoundException {
        if (name.equals("Testowa")) {
            return findClass(name);
        }
        return super.loadClass(name);
    }
}
 */

/**
class Exceptions{
    public static void main(String[] args){
        try{
            multiExceptions();
        }catch(ExceptionA | ExceptionB e){
            e.printStackTrace();
        }catch(ExceptionC e){
            e.printStackTrace();
            e = new ExceptionC();
        }
    }

    private static void multiExceptions() throws ExceptionA, ExceptionB, ExceptionC{}
}

class ExceptionA extends Exception {}
class ExceptionB extends Exception {}
class ExceptionC extends Exception {}
 */

/**
class Start{
    String testFinally(){
        try{
            return "Powód oryginalny";
        }
        finally{
            return "Finally";
        }
    }

    public static void main(String[] argv){
        System.out.println((new Start()).testFinally());
    }
}
 */

/**
public void oblicz (double bok){
    double pole = Oblicz.poleKwadratu(bok);
    assert (pole >= 0.0) : "Ujemne pole kwadratu";

    double przekatna = Oblicz.przekatnaKwadratu(bok);
    assert (pole >= 0.0) : "Przekątna kwadratu mniejsza od 0.0";

    double obwod = Oblicz.obwodKwadratu(bok);
    assert (pole >= 0.0) : "Obwód kwadratu mniejszy od 0.0";
}
 */

/**
class Start{
    static void metodaZAsercja(int i){
        assert(i!=0) : "Argument równy zero";
        System.out.println("I = " + i);
    }

    public static void main(String[] argv){
        metodaZAsercja(1);
        metodaZAsercja(0);
        System.out.println("Aby włączyć asercje kompiluj program: java -enableassertions Start");
    }
}
 */

/**
class Start{
    private static boolean asercjeWlaczone = false;

    public static void main(String[] argv){
        assert asercjeWlaczone = true;

        if(asercjeWlaczone){
            System.out.println("Asercje włączone");
        }
        else{
            System.out.println("Asercje nie włączone");
        }
    }
}
 */

/**
class Main{
    public static void main(String[] argv){
        Thread mth = new MyThread();
        mth.start();
        for(int i=0; i<100; i++){
            threadCallingCard(i);
        }
    }

    public static void threadCallingCard(int i){
        System.out.println(i+1 + ". " + Thread.currentThread().getName());
    }
}

class MyThread extends Thread{
    public void run(){
        for(int i=0; i<100; i++){
            Main.threadCallingCard(i);
        }
    }
}
 */

/**
class Main{
    public static void main(String[] argv){
        Thread mth = new Thread(new MyWorker());
        mth.start();
        for(int i=0; i<100; i++){
            threadCallingCard(i);
        }
    }

    public static void threadCallingCard(int i){
        System.out.println(i+1 + ". " + Thread.currentThread().getName());
    }
}

class MyWorker implements Runnable{
    public void run(){
        for(int i=0; i<100; i++){
            Main.threadCallingCard(i);
        }
    }
}
 */

/**
public class Wspoldzielenie{
    public static void main(String[] argv) throws InterruptedException{
        ObiektDoWspoldzielenia obiekt = new ObiektDoWspoldzielenia();

        Thread th = new Thread(new Runnable(){
            public void run(){
                obiekt.pole = 123;
            }
        });

        th.start();
        th.join();

        System.out.println(obiekt.pole);
    }
}

class ObiektDoWspoldzielenia{
    int pole;
}
 */

/**
//Błędny kod:
class Widocznosc{
    private static boolean pole = true;
    public static void main(String[] argv) throws InterruptedException{
        Thread set = new Thread(new Runnable(){
            public void run(){
                try{
                    Thread.sleep(1000);
                }catch(InterruptedException e){}
                pole = false;
                System.out.println("Pole zmieniono na " + pole);
            };
        });
        Thread read = new Thread(new Runnable(){
            public void run(){
                while(pole) {}
                System.out.println("Koniec pracy wątku");
            }
        });

        read.start();
        set.start();
        read.join();
        System.out.println("Koniec programu");
    }
}
 */

/**
//Błędny kod
class Main{
    private static int licznik;

    public static void main(String[] args) throws InterruptedException{
        Thread th = new Thread(new Runnable(){
            public void run(){
                licz();
            };
        });
        th.start();
        licz();
        th.join();
        System.out.println("Stan licznika: " + licznik);
    }

    private static void licz(){
        for(int i=0; i<10000; i++){
            licznik++;
        }
    }
}
 */

/**
import java.util.concurrent.atomic.AtomicInteger;
class Main{
    //private static int licznik;
    private static AtomicInteger licznik = new AtomicInteger();

    public static void main(String[] args) throws InterruptedException{
        Thread th = new Thread(new Runnable(){
            public void run(){
                licz();
            };
        });
        th.start();
        licz();
        th.join();
        System.out.println("Stan licznika: " + licznik);
    }

    private static void licz(){
        for(int i=0; i<10000; i++){
            licznik.incrementAndGet();
        }
    }
}
 */

/**
import java.util.Random;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicLong;
class Niepodzielnosc {
    static AtomicInteger value = new AtomicInteger();
    static AtomicLong factorial = new AtomicLong();
    static Random rnd = new Random();

    public static void main(String[] args) {
        Thread.ofPlatform().start( new Testowanie() );
        Thread.ofPlatform().start( new Testowanie() );
    }

    static class Testowanie implements Runnable {
        public void run() {
            int n; long expected, factorial;
            while ( true ) {
                n = 4 + rnd.nextInt(5);        // losowy argument
                expected = factorial(n);        // poprawny wynik dla porownania
                factorial = smartFactorial(n);  // rozwiazanie "inteligentne"
                if ( expected != factorial ) {
                    System.err.println( n + "! = " + expected + " vs " + factorial);
                }
            }
        }
    }

    static long smartFactorial( int n ) {
        if ( value.get() == n )              // moze mamy gotowy wynik?
            return factorial.get();
        value.set(n);                        // jednak nie mamy, to
        factorial.set(factorial(n));         // zapamietujemy rozwiazanie
        return factorial.get();
    }

    static long factorial( int n ) // tu faktycznie liczymy silnie
}
 */

/**
import java.util.Random;
class Niepodzielnosc {
    static int value;
    long factorial;
    static Random rnd = new Random();

    public static void main(String[] args) {
        Thread.ofPlatform().start( new Testowanie() );
        Thread.ofPlatform().start( new Testowanie() );
    }

    static class Testowanie implements Runnable {
        public void run() {
            int n; long expected, factorial;
            while ( true ) {
                n = 4 + rnd.nextInt(5);        // losowy argument
                expected = factorial(n);        // poprawny wynik dla porownania
                factorial = smartFactorial(n);  // rozwiazanie "inteligentne"
                if ( expected != factorial ) {
                    System.err.println( n + "! = " + expected + " vs " + factorial);
                }
            }
        }
    }

    synchronized static long smartFactorial( int n ) {
        if ( value == n )              // moze mamy gotowy wynik?
            return factorial;
        value = n;                        // jednak nie mamy, to
        factorial = factorial(n);       // zapamietujemy rozwiazanie
        return factorial;
    }

    static long factorial( int n ) // tu faktycznie liczymy silnie
}
 */

/**
class Kasowanie implements Runnable {
    public void run() {
        int r;
        while (true) {                    // kasowanie danych
            r = rnd.nextInt(100);
            synchronized (dane) {
                if (dane.contains(r)) {       // sprawdz
                    System.out.println("W zbiorze jest " + r + " to kasujemy");
                    if (!dane.remove(r))      // wykonaj
                        System.out.println("W zbiorze nie ma " + r + " !!!!!!!!");
                }
            }
        }
    }
}

new Thread(new Kasowanie()).start();
new Thread(new Kasowanie()).start();
while (true) {                            // wstawianie danych
        dane.add(rnd.nextInt(100));
        }
 */

/**
class BrakWspolpracy {
    static boolean koniecCzekania;
    static Object blokada = new Object();

    public static void main(String[] args) {
        Thread.ofPlatform().start( new PracownikA() );
        Thread.ofPlatform().start( new PracownikB() );
    }

    static class PracownikA implements Runnable {
        public void run() {
            synchronized (blokada) {
                while (!koniecCzekania) {} // czekam na zmiane
                System.out.println("koniec czekania");
            }
        }
    }

    static class PracownikB implements Runnable {
        public void run() {
            synchronized (blokada) {
                koniecCzekania = true;      // zmiana
            }
        }
    }
}
 */

/**
class BrakWspolpracy {
    static boolean koniecCzekania;
    static Object blokada = new Object();

    public static void main(String[] args) {
        Thread.ofPlatform().start( new PracownikA() );
        Thread.ofPlatform().start( new PracownikB() );
    }

    static class PracownikA implements Runnable {
        public void run() {
            synchronized (blokada) {
                while (!koniecCzekania) {
                    try {
                        blokada.wait();  // nie moge pracowac, to ide spac
                    } catch ( InterruptedException e ) {}
                }
                System.out.println("Koniec czekania");
            }
        }
    }

    static class PracownikB implements Runnable {
        public void run() {
            synchronized (blokada) {
                koniecCzekania = true;
                blokada.notify();  // zmienilem stan, to informuje innych
            }
        }
    }
}
 */

/**
class BrakWspolpracy {
    static boolean koniecCzekania;
    static Object blokada = new Object();

    static Thread watekA;

    public static void main(String[] args) {
        watekA = new Thread( new PracownikA() );
        watekA.start();
        Thread.ofPlatform().start( new PracownikB() );
    }

    static class PracownikA implements Runnable {
        public void run() {
            synchronized (blokada) {
                while (!koniecCzekania) {
                    try {
                        blokada.wait();
                    } catch ( InterruptedException e ) {
                        break;  // koniec petli while
                    }
                }
                System.out.println("Koniec czekania");
            }
        }
    }

    static class PracownikB implements Runnable {
        public void run() {
            synchronized (blokada) {
                koniecCzekania = true;
                watekA.interrupt();  // przerwywamy watek A
            }
        }
    }
}
 */

/**
class Main {
    public static void main(String[] args) {
        ThreadGroup pracownicy = new ThreadGroup("Grupa pracowników");
        new Thread(pracownicy, new Worker()).start();
        new Thread(pracownicy, new Worker()).start();
        pracownicy.interrupt();
        System.out.println("Koniec pracy");
    }
}

class Worker implements Runnable {
    public void run() {
        Thread t = Thread.currentThread();
        System.out.println("Watek " + t.getName() + " o id " + t.threadId() +
                " nalezy do grupy " + t.getThreadGroup().getName());
        sleep(10000);
    }

    private void sleep(long msleep) {
        try {
            Thread.sleep(msleep);
        } catch (InterruptedException e) {}
    }
}
 */

/**
class IndywidualnaProceduraObslugiWyjatku
        implements Thread.UncaughtExceptionHandler {

    public void uncaughtException(Thread t, Throwable e) {
        System.out.println( "W watku " + t.getName() +
                " pojawil sie wyjatek " + e);
    }
}

class GrupowaProceduraObslugiWyjatku extends ThreadGroup {
    GrupowaProceduraObslugiWyjatku(String name) {
        super( name );
    }

    public void uncaughtException(Thread t, Throwable e) {
        System.out.println( "Obsluga grupowa. W watku " + t.getName() +
                " pojawil sie wyjatek " + e);
    }
}

class ObslugaWyjatkuOstatninejSzansy
        implements Thread.UncaughtExceptionHandler {

    public void uncaughtException(Thread t, Throwable e) {
        System.out.println( "Oto ostatnia szansa. W " + t.getName() +
                " pojawil sie wyjatek " + e);
    }
}



class WyjatkowyPracownik implements Runnable{
    public void run(){
        sleep(1000);
        throw new RuntimeException("Ja już dłużej nie mogę...");
    }

    private void sleep(long msleep){
        try{
            Thread.sleep(msleep);
        }catch (InterruptedException e){
        }
    }
}



class Main{
    public static void main(String[] args) throws Exception {
        // Test 1: Handler indywidualny
        System.out.println("=== Test 1: Handler indywidualny ===");
        Thread th1 = new Thread(new WyjatkowyPracownik());
        th1.setUncaughtExceptionHandler(new IndywidualnaProceduraObslugiWyjatku());
        th1.start();
        th1.join();

        // Test 2: Handler grupowy
        System.out.println("\n=== Test 2: Handler grupowy ===");
        GrupowaProceduraObslugiWyjatku grupa =
                new GrupowaProceduraObslugiWyjatku("Grupa");
        Thread th2 = new Thread(grupa, new WyjatkowyPracownik());
        th2.start();
        th2.join();

        // Test 3: Handler domyślny
        System.out.println("\n=== Test 3: Handler domyślny ===");
        Thread.setDefaultUncaughtExceptionHandler(new ObslugaWyjatkuOstatninejSzansy());
        Thread th3 = new Thread(new WyjatkowyPracownik());
        th3.start();
        th3.join();

        System.out.println("\nKoniec pracy");
    }
}
 */

/**
class Reentrant{
    private int v;

    public static void main(String[] args){
        Reentrant r = new Reentrant();
        r.setAndGet(10);
        System.out.println(r.incrementAndGet(15));
    }

    synchronized public int setAndGet(int v){
        return this.v = v;
    }

    synchronized public int get(){
        return v;
    }

    synchronized public int incrementAndGet(int v){
        return setAndGet(get() + v);
    }
}
 */

/**
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Try {
    private final static int ARGS = 20;
    private final Map<Integer, Long> factorials = new HashMap<>();
    private final Lock lock = new ReentrantLock();
    private final Condition condition = lock.newCondition();
    private final BlockingQueue<Integer> arguments = new ArrayBlockingQueue<>(ARGS);

    {
        for (int i = 1; i <= ARGS; i++)
            arguments.add(i);

        Thread.ofPlatform().start(new Worker());
        Thread.ofPlatform().start(new Worker());
    }
    // umieszczenie zadan w kolejce i start watkow

    public Try() {
        lock.lock();  // zakladamy blokade
        while (factorials.size() < ARGS) {  // czy wszystkie dane w mapie?
            try {
                System.out.println("Jeszcze nie gotowe. Ide spac.");
                condition.await();
            } catch (InterruptedException e) {
            }
        }
        lock.unlock();  // zdejmujemy blokade
        System.out.println("Cache przygotowany: ");
        System.out.println(factorials);
    }

    class Worker implements Runnable {
        private Map<Integer, Long> localCache = new HashMap<>();

        @Override
        public void run() {
            Integer arg;
            while ((arg = arguments.poll()) != null) {  // pobranie danych
                localCache.put(arg, factorial(arg));     // licze silnie

                if (lock.tryLock()) {  // proba dostepu do glownej mapy
                    factorials.putAll(localCache);  // przekazanie danych
                    lock.unlock();                  // zdjecie blokady
                    System.out.println("Dodaje moje dane: " + localCache);
                    localCache.clear();  // usuniecie danych z lokalnej mapy
                } else {
                    System.out.println("Nie otrzymano blokady");
                }
            }
            lock.lock();  // koniec obliczen, musze jeszcze cos zrobic
            if (localCache.size() > 0) {  // sa dane do przepisania
                System.out.println("Ostatni raz dodaje dane: " + localCache);
                factorials.putAll(localCache);
            }
            condition.signal();  // wybudzenie main musi byc po lock()
            lock.unlock();       // otwarcie blokady
        }


        private long factorial(int n) {
            long result = 1;
            for (int i = 2; i <= n; i++) {
                result *= i;
            }
            return result;
        }
    }

    public static void main(String[] args) {
        new Try();
    }
}
 */

/**
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.CyclicBarrier;

class Try {
    private final CyclicBarrier barrier = new CyclicBarrier(3); // 3 watki

    private final static int ARGS = 20;
    private final Map<Integer,Long> factorials = new HashMap<>();
    private final BlockingQueue<Integer> arguments = new ArrayBlockingQueue<>(ARGS);

    {
        for (int i = 1; i <= ARGS; i++)
            arguments.add(i);

        Thread.ofPlatform().start(new Worker());
        Thread.ofPlatform().start(new Worker());
    }

    public Try() {
        try {
            barrier.await();  // oczekiwanie na inne watki
        } catch (Exception e) {
        }
        System.out.println("Cache przygotowany: ");
        System.out.println(factorials);  // await daje widocznosc zmian!
    }

    class Worker implements Runnable {
        private Map<Integer, Long> localCache = new HashMap<>();

        @Override
        public void run() {
            Integer arg;
            while ((arg = arguments.poll()) != null) {
                localCache.put(arg, factorial(arg));
            }

            if (localCache.size() > 0) {
                System.out.println("Ostatni raz dodaje dane: " + localCache);
                synchronized (factorials) {
                    factorials.putAll(localCache);
                }
            }
            try {
                barrier.await();  // oczekiwanie na inne watki
            } catch (Exception e) {}
        }

        private long factorial(int n) {
            long result = 1;
            for (int i = 2; i <= n; i++) {
                result *= i;
            }
            return result;
        }
    }


    public static void main(String[] args) {
        new Try();
    }
}
 */

/**
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

class ReadWriteCounter {
    private final ReadWriteLock lock = new ReentrantReadWriteLock();
    private final Lock readLock = lock.readLock();   // ochrona odczytu
    private final Lock writeLock = lock.writeLock(); // ochrona zapisu
    private int counter;  // pole, które trzeba chronic

    public int get() {
        try {
            readLock.lock();
            System.out.println( "Read - start");
            return counter;
        } finally {  // to zawsze sie wykona!
            System.out.println( "Read - end");
            readLock.unlock();
        }
    }

    public int incrementAndGet() {
        try {
            writeLock.lock();
            System.out.println( "Write - start");
            return ++counter;
        } finally {  // to zawsze sie wykona
            System.out.println( "Write - end");
            writeLock.unlock();
            Thread.yield();  // watek oddaje CPU dla czytajacych
        }
    }
}


class Test{
    private static final ReadWriteCounter counter = new ReadWriteCounter();
    private static final int INCREMENTER_THREADS = 3;
    private static final AtomicInteger finished = new AtomicInteger();

    public static void main(String[] args) throws InterruptedException {
        for (int i = 0; i < INCREMENTER_THREADS; i++)
            Thread.ofPlatform().start(new Incrementer());
        Thread thA = Thread.ofPlatform().start(new Reader());
        Thread thB = Thread.ofPlatform().start(new Reader());
        Thread thC = Thread.ofPlatform().start(new Reader());
        thA.join();     thB.join();     thC.join();
    }

    static class Incrementer implements Runnable {
        public void run() {
            for (int i = 0; i < 100000; i++) {
                counter.incrementAndGet();
            }
            finished.incrementAndGet();  // watek zakoczyl prace
        }
    }

    static class Reader implements Runnable {
        public void run() {
            while (finished.get() != INCREMENTER_THREADS) {
                System.out.println("Aktualnie mamy: " + counter.get());
            }
            System.out.println("Wynik koncowy: " + counter.get());
        }
    }
}
 */

/**
class Factorial implements Callable<Long>{
    private int n;

    Factorial(int n){
        this.n = n;
    }

    @Override
    public Long call() throws Exception{
        System.out.println("Thread " + Thread.currentThread().getName() + " liczy " + n + "!");

        if(n>20){
            throw new RuntimeException("Argument too big");
        }

        long result = 1;
        for(int i=1; i<=n; i++){
            result*=i;
        }

        return result;
    }
}
 */

/**
class Call {
    private static final int MAX_THREADS = 4;

    public static void main(String[] args) throws InterruptedException {
        List<Callable<Long>> zadania = new ArrayList<>();

        for (int i = 0; i < 22; i++) {
            zadania.add(new Factorial(i)); // zadania do policzenia
        }

        ExecutorService egzekutor = Executors.newFixedThreadPool(MAX_THREADS);
        List<Future<Long>> obserwatorzy = egzekutor.invokeAll(zadania);

        Long result;
        for (int i = 0; i < 22; i++) {

            System.out.println("Zadanie " + i + " zakonczone:");

            try {
                result = obserwatorzy.get(i).get();
                System.out.println(" - wynikiem " + result);
            } catch (Exception e) {
                System.out.println(" - wyjatkiem " + e);
            }
        }

        egzekutor.shutdown();  // bez tej linijki program sie nie zakonczy
    }
}
 */

/**
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
class Zegarek {

    public static void main(String[] args) {
        ScheduledExecutorService ses = Executors.newScheduledThreadPool(2);
        ses.scheduleAtFixedRate(new Minutnik("FixedRate"), 0, 1000, TimeUnit.MILLISECONDS);
        ses.scheduleWithFixedDelay(new Minutnik("FixedDelay"), 0, 1000, TimeUnit.MILLISECONDS);
    }

    static class Minutnik implements Runnable {
        private long lastCallAt = System.currentTimeMillis();
        private final String name;

        public Minutnik(String name) {
            this.name = name;
        }

        public void run() {
            System.out.println("Tu " + name + " od zakonczenia poprzedniego wywolania minelo " + (System.currentTimeMillis() - lastCallAt));
            try {
                Thread.sleep(175);  // tu symulujemy prace zadania
            } catch (InterruptedException e) {}
            lastCallAt = System.currentTimeMillis();
        }
    }
}
 */

/**
class Porownanie{
    public static void main(String[] args){
        test(new A());
        System.out.println("-----------------------");
        test(new B());
    }

    public static void test(A ref){
        if(ref instanceof A){
            System.out.println("Obiekt zgodny z typem A");
        }

        if(ref.getClass() == A.class){
            System.out.println("Obiekt jest instancją A");
        }
    }
}

class A{}
class B extends A{}
 */

/**
import java.lang.reflect.Field;
import java.util.List;

public class FieldSpy<T> {
    public boolean[][] b = {{ false, false }, { true, true }};
    public String name = "Alice";
    public List<Integer> list;
    public T val;

    public static void main(String... args) {
        try {
            Class<?> c = Class.forName(args[0]);
            Field f = c.getField(args[1]);
            System.out.format("Type: %s%n", f.getType());
            System.out.format("GenericType: %s%n", f.getGenericType());
        } catch ( Exception e ) {}
    }
}
 */

/**
class Start{
    public static int poleDoZabawy = 123;

    public static void main(String[] argv) throws Exception{
        Class c = Start.class;
        Start st = new Start();

        java.lang.reflect.Field f = c.getDeclaredField("poleDoZabawy");

        System.out.println("Start> Pole f = " + f.getInt(st));
        f.setInt(st, 321);
        System.out.println("Start> Pole f = " + f.getInt(null));
    }
}
 */

/**
import java.lang.reflect.Field;

class Enkapsulacja {
    private int i = 10;

    public int add(int j) {
        return i + j;
    }
}

class Start {
    private static void abrakadabra(Enkapsulacja e, int newValue) throws Exception {
        Class<? extends Enkapsulacja> eClass = e.getClass();
        Field i = eClass.getDeclaredField("i");
        i.setAccessible(true);
        i.setInt(e, newValue);
    }

    public static void main(String[] args) throws Exception {

        Enkapsulacja e = new Enkapsulacja();

        System.out.println("e.add(10) = " + e.add(10));
        abrakadabra(e, 123);
        System.out.println("e.add(10) = " + e.add(10));
    }
}
 */

/**
import java.lang.reflect.Method;
import java.io.PrintStream;
class Start {
    public static void main(String[] args) throws Exception {
        PrintStream out = System.out;
        String fmt = "%-15s: %s%n";
        Class<?> c = Class.forName(args[0]);
        Method[] allMethods = c.getDeclaredMethods();
        for (Method m : allMethods) {
            if (!m.getName().equals(args[1])) {
                continue;
            }
            out.format(fmt, "ReturnType", m.getReturnType());

            Class<?>[] pType = m.getParameterTypes();
            for (int i = 0; i < pType.length; i++) {
                out.format(fmt, "ParameterType", pType[i]);
            }

            Class<?>[] xType = m.getExceptionTypes();
            for (int i = 0; i < xType.length; i++) {
                out.format(fmt, "ExceptionType", xType[i]);
            }
        }
    }
}
 */

/**
class DoZabawy {
    public static int metodaDoZabawy( String s ) {
        System.out.println( "DoZabawy::metodaDoZabawy > " + s );
        return 12345;
    }
}

class Start {
    public static void main( String[] argv ) throws Exception {

        String nazwaKlasy = "DoZabawy";
        String nazwaMetody = "metodaDoZabawy";

        Class<?> c = Class.forName( nazwaKlasy );
        java.lang.reflect.Method m = c.getDeclaredMethod( nazwaMetody,
                java.lang.String.class );
        Integer ret = (Integer) m.invoke( null, "Chwila prawdy..." );
        System.out.println( "Metoda zwrocila liczbe " + ret );
    }
}
 */

/**
class DoZabawy {
    public int metodaDoZabawy( String s ) {
        System.out.println( "DoZabawy::metodaDoZabawy > " + s );
        return 12345;
    }
}

class Start {
    public static void main( String[] argv ) throws Exception {

        String nazwaKlasy = "DoZabawy";
        String nazwaMetody = "metodaDoZabawy";

        Class<?> c = Class.forName( nazwaKlasy );
        java.lang.reflect.Method m = c.getDeclaredMethod( nazwaMetody, java.lang.String.class );

        java.lang.reflect.Constructor constr = c.getDeclaredConstructor( );

        Object o = constr.newInstance();

        Integer ret = (Integer) m.invoke( o, "Chwila prawdy..." );
        System.out.println( "Metoda zwrocila liczbe " + ret );
    }
}
 */

/**
import java.lang.reflect.Method;
class RefleksyjnyKalkulator{
    public static void main( String[] args ) throws Exception{
        Class<Math> cMath = Math.class;
        String function = args[0];
        String argument = args[1];

        Method m = cMath.getDeclaredMethod(function, double.class);
        double value = (double) m.invoke(null, Double.valueOf(argument));

        System.out.println(function + "(" + argument + ") = " + value);
    }
}
 */

/**
@interface InformacjeOKlasie{
    String czasUtworzenia();
    String autor();
    int wersja();
}

@InformacjeOKlasie(
        autor = "Piotr Oramus",
        czasUtworzenia = "sro, 18 gru 2024, 16:42:48 CET",
        wersja = 5
)

class Start{
    public static void main(String[] argv){
        System.out.println("Mała klasa z adnotacją");
    }
}
 */

/**
interface JustInterface extends Annotation{
    public void doIt();
}

class AnnotationImplementation implements JustInterface{
    public void doIt(){
        System.out.println("To tak nie działa");
    }
}

class Main{
    public static void main(String[] args){
        JustInterface iface = new AnnotationImplementation();
        iface.doIt();
    }
}
 */

/**
@interface RevisionNumber{
    int wersja();
}

@interface InformacjeOKlasie{
    String czasUtworzenia();
    String autor() default "Piotr Marek Oramus";
    RevisionNumber numerRewizji();
}

@InformacjeOKlasie(
        czasUtworzenia = "sro, 18 gru 2024, 16:42:48 CET",
        numerRewizji = @RevisionNumber( wersja = 4)
)

class Start{
    public static void main(String[] argv){
        System.out.println("Mały program z adnotacją");
    }
}
*/

/**
@interface Tested {}

@interface RevisionNumber {
    int[] value();
    String txt() default "";
}

@java.lang.annotation.Target(java.lang.annotation.ElementType.TYPE)
@interface InformacjeOKlasie {
    String autor() default "Piotr Marek Oramus";
    RevisionNumber numerRewizji();
}

@Tested
@InformacjeOKlasie(
        numerRewizji = @RevisionNumber({4, 0, 1})
)
class Start {
    public static void main(String[] argv) {
        System.out.println("Mały program z adnotacją");
    }
}
 */

/**
import java.lang.annotation.Repeatable;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
@Repeatable(Autorzy.class)
@interface Autor {
    String value() default "nikt";
}

@Retention(RetentionPolicy.RUNTIME)
@interface Autorzy {
    Autor[] value();
}

@Autor("Piotr Oramus")
@Autor("Jan Nowak")
class Powtarzalna {
    public static void main(String[] args) {
        Class<Powtarzalna> obiektClass = Powtarzalna.class;
        Autorzy kontener = obiektClass.getAnnotation(Autorzy.class);

        for (Autor autor : kontener.value()) {
            System.out.println("Autorem jest: " + autor.value());
        }
    }
}
 */

/**
@Path("myresource")
public class MyResource{
    @GET
    @Produces(MediaType.TEXT_PLAIN)
    public String getIt(){
        return "To żyje!";
    }
}
 */

/**
class Klasa{
    private static Stream<Arguments> examplesProvider() {
        return Stream.of(
                Arguments.of("123 4a bcd e12 34", "1234abcde1234"),
                Arguments.of("12 303 2", "123222"),
                Arguments.of("1230301 add c101", "123addc1addc1addc1")
        );
    }

    @ParameterizedTest
    @MethodSource("examplesProvider")
    public void examplesTest(String string2add, String expected) {
        try {
            Arrays.stream(string2add.split(" "))
                    .forEach(this::decode);

            result = getBufferAndTestNull();

            assertTrue(
                    result.contentEquals(expected),
                    "Wynik nie zgadza sie z oczekiwanym."
            );
        }
        catch (Exception e) {
            e.printStackTrace();
            fail("Test zakonczony wyjatkiem " + e.toString());
        }
    }
}
 */

/**
@FunctionalInterface
interface InterfejsFunkcyjny{
    void metodaAbstrakcyjna(String txt);
}

class Lambda{
    public static void main(String[] args){
        uruchom(new InterfejsFunkcyjny(){
            @Override
            public void metodaAbstrakcyjna(String txt){
                System.out.println("Wywołano z argumentem: " + txt);
            }
        });
    }

    private static void uruchom(InterfejsFunkcyjny intFun){
        intFun.metodaAbstrakcyjna("Napis testowy");
    }
}
 */

/**
@FunctionalInterface
interface InterfejsFunkcyjny{
    void metodaAbstrakcyjna(String txt);
}

class Lambda{
    public static void main(String[] args){
        uruchom(txt -> System.out.println(txt));
    }

    private static void uruchom(InterfejsFunkcyjny intFun){
        intFun.metodaAbstrakcyjna("Napis testowy");
    }
}
 */

/**
class WolneZmienne{
    private static Box bField = new Box().set(1);
    public static void main(String[] args) {
        show(new Box().set(2));
    }

    private static void show(Box bPar){
        Box bVar = new Box().set(3);
        execute(() -> {
            Box lVar = new Box().set(4);
            System.out.println("Field      : " + bField);
            System.out.println("Parameter  : " + bPar);
            System.out.println("Method var : " + bVar);
            System.out.println("Local  var : " + lVar);
        });
    }

    private static void execute(Runnable run){
        run.run();
    }
}

class Box{
    public int i;
    public Box set(int v){
        i = v;
        return this;
    }
    public String toString(){
        return "i = " + i;
    }
}
 */

/**
class LambdaThreads{
    private Box bField = new Box();

    public static void main(String[] args) throws Exception{
        LambdaThreads lt = new LambdaThreads();
        Thread t1 = lt.startThread();
        Thread t2 = lt.startThread();
        Thread t3 = lt.startThread();
        t1.join();
        t2.join();
        t3.join();

        System.out.println("Stan i to " + lt.bField.i);
    }

    private Thread startThread(){
        return Thread.ofPlatform().start(() -> {
            synchronized (this){
                for(int i=0; i<1000000; i++){
                    bField.i++;
                }
            }
        });
    }
}

class Box{
    public int i;
}
 */

/**
class AtomicThreads{
    private Box bField = new Box();

    public static void main(String[] args) throws Exception{
        AtomicThreads lt = new AtomicThreads();
        Thread t1 = lt.startThread();
        Thread t2 = lt.startThread();
        Thread t3 = lt.startThread();
        t1.join();
        t2.join();
        t3.join();

        System.out.println("Stan i to " + lt.bField.i);
    }

    private Thread startThread(){
        return Thread.ofPlatform().start(new Runnable() {
            @Override
            public void run(){
                synchronized (this){
                    for(int i=0; i<1000000; i++){
                        bField.i++;
                    }
                }
            }
        });
    }
}

class Box{
    public int i;
}
 */

/**
class AtomicThreads{
    private Box bField = new Box();

    public static void main(String[] args) throws Exception{
        AtomicThreads lt = new AtomicThreads();
        Thread t1 = lt.startThread();
        Thread t2 = lt.startThread();
        Thread t3 = lt.startThread();
        t1.join();
        t2.join();
        t3.join();

        System.out.println("Stan i to " + lt.bField.i);
    }

    private Thread startThread(){
        return Thread.ofPlatform().start(this::increment);
    }

    private void increment(){
        synchronized (this){
            for(int i=0; i<1000000; i++){
                bField.i++;
            }
        }
    }
}

class Box{
    public int i;
}
 */

/**
import java.util.*;
class Inside{
    public static void main(String[] args){
        Map<String, String> dictPl2Fr = Map.of("kot", "chat", "pies", "chein");
        Map<String, String> dictPl2En = Map.of("kot", "cat", "pies", "dog");
        show(dictPl2Fr);
        show(dictPl2En);
    }

    private static void show(Map<String, String> dict){
        dict.entrySet().forEach(Inside::show);
    }

    private static void show(Map.Entry<String, String> entry){
        System.out.println("Słowo " + entry.getValue() + " oznacza " + entry.getKey());
    }
}
 */

/**
import java.util.*;
class Limits{
    public static void main(String[] args){
        List<Integer> testList = List.of(1, 9, 12, 22, 25, 13, 33);
        myForEach(testList, 12, 13);
        System.out.println();
        System.out.println("-".repeat(40));
        inForEach(testList, 12, 13);
        System.out.println();
    }

    private static void myForEach(List<Integer> i, int skip, int stop){
        for(Integer entry : i){
            if(entry == skip) continue;
            if(entry == stop) break;
            System.out.println(entry + "; ");
        }
    }

    private static void inForEach(List<Integer> i, int skip, int stop){
        i.forEach((entry) -> {
            if(entry==stop) return;
            System.out.println(entry + "; ");
        });
    }
}
 */

/**
import java.util.*;
class Limits{
    public static void main(String[] args){
        List<Integer> testList = List.of(1, 9, 12, 22, 25, 13, 33);
        myForEach(testList, 12, 13);
        internalForEach(testList, 12, 13);
    }

    private static void myForEach(List<Integer> i, int skip, int stop){
        for(Integer entry : i){
            if(entry == stop) return;
            System.out.println(entry + "; ");
        }
    }

    private static void internalForEach(List<Integer> i, int skip, int stop){
        try {
            i.forEach((entry) -> {
                if (entry == stop) throw new RuntimeException();
                System.out.println(entry + "; ");
            });
        } catch (RuntimeException e) {
        }
    }
}
 */

/**
import java.util.Random;
import java.util.stream.Stream;

public class Generator{
    public static void main(String[] args){
        Random rnd = new Random();

        Stream<Integer> s1 = Stream.generate(() -> 1 + rnd.nextInt(10)).limit(10);

        Stream<Integer> s2 = Stream.iterate(20, i -> i + 1).limit(10);

        Stream<Integer> s3 = Stream.iterate(40, i -> i < 50, i -> i + 1);

        Stream.concat(s1, Stream.concat(s2, s3)).forEach(System.out::println);
    }
}
 */

/**
class Squares{
    public static void main(String[] args){
        double result = java.util.stream.Stream.of(1.0, 2.0, 2.5, 10.6, 10.0).
                filter(i->i>5).
                map(i->i*i).
                peek(a->System.out.println("Pole " + a)).
                reduce(0.0, (x,y) -> x+y);
        System.out.println("Sumaryczne pole " + result);
    }
}
 */

/**
import java.util.Collection;
import java.util.stream.Collectors;
import java.util.stream.Stream;
class SquaresCollection{
    public static void main(String[] args){
        Collection<Double> result = Stream.of(1.0, 2.0, 2.5, 10.6, 10.0, 20.0, 10.0).
                filter(i->i>5).
                map(i->i*i).
                peek(a->System.out.println("Pole " + a)).
                collect(Collectors.toSet());
        System.out.println("Zbiór pól " + result);
    }
}
 */

/**
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;
class SquaresCollection{
    public static void main(String[] args){
        Map<Double, Long> result = Stream.of(1.0, 2.0, 2.5, 10.6, 10.0, 20.0, 10.0).
                //filter(i->i>5).
                map(i->i*i).
                peek(a->System.out.println("Pole " + a)).
                collect(Collectors.groupingBy(i->i, Collectors.counting()));
        System.out.println("Zbiór danych " + result.entrySet());
    }
}
 */

/**
import java.util.*;
import java.util.stream.Stream;
class ParallelStream{
    public static void main(String[] args){
        List<Integer> input = new Random().ints(5000000, 0, 100).boxed().toList();
        test(input.stream());
        test(input.parallelStream());
    }

    private static void test(Stream<Integer> stream){
        long start = System.currentTimeMillis();
        double result = stream.filter(i->i>50).
                mapToInt(i->i-50).
                average().getAsDouble();
        long finish = System.currentTimeMillis();

        System.out.println("Uzyskano " + (stream.isParallel()?"współbieżnie " : "")
        + "wynik " + result + " po " + (finish - start) + " msec");
    }
}
 */

/**
class Obserwator{
    private static volatile boolean flag;
    private static volatile long changedAt;

    public static class MyObserver implements Runnable{
        private final long resolution;

        public MyObserver(int resolution){
            this.resolution = resolution;
        }

        @Override
        public void run(){
            while (!flag){
                sleep(resolution);
            }
            System.out.println("Tu wątek: " + Thread.currentThread().getName() +
            " wykryłem zmianę flagi! Opóźnienie: " + (System.currentTimeMillis() - changedAt));
        }
    }

    public static class Changer implements Runnable{
        @Override
        public void run(){
            sleep(new Random().nextInt(10000) + 1000);
            flag = true;
            changedAt = System.currentTimeMillis();
            System.out.println("Tu Changer zmieniłem stan flagi");
        }
    }

    public static void main(String[] args) throws InterruptedException{
        Thread obs1 = Thread.ofPlatform().start(new MyObserver(5));
        Thread obs2 = Thread.ofPlatform().start(new MyObserver(50));
        Thread.ofPlatform().start(new Changer());

        obs1.join();
        obs2.join();
    }

    private static void sleep(long msec){
        try{
            Thread.sleep(msec);
        }catch (InterruptedException e){
        }
    }
}
 */

/**
import java.util.*;
import java.util.function.LongConsumer;
class Changer implements Runnable{
    private List<LongConsumer> observers = Collections.synchronizedList(new ArrayList<>());

    public void register(LongConsumer observer){
        observers.add(observer);
    }

    @Override
    public void run() {
        Thread.sleep(new Random().nextInt(10000) + 10000);
        flag = true;
        long changedAt = System.currentTimeMillis();
        System.out.println("Tn Changer zmieniłem stan flagi");
        observers.forEach(observer -> observer.accept(changedAt));
    }
}

class MyObserver implements Runnable, LongConsumer{
    public MyObserver(Changer changer){
        changer.register(this);
    }

    synchronized public void accept(long value){
        System.out.println(Thread.currentThread().getName() + "Otrzymałem informacje z opóźnieniem" +
                (System.currentTimeMillis() - value));
        notify();
    }

    synchronized public void run(){
        try{
            System.out.println(Thread.currentThread().getName() + " idę spać");
            wait();
            System.out.println(Thread.currentThread().getName() + " wybudzono. " + " Stan flagi to " + flag);
        } catch (InterruptedException e) {
            //throw new RuntimeException(e);
        }
    }
}

class BetterObserwator{
    private static volatile boolean flag;

    public static void main(String[] args) throws InterruptedException{
        Changer changer = new Changer();
        Thread obs1 = Thread.ofPlatform().start(new MyObserver(changer));
        Thread obs2 = Thread.ofPlatform().start(new MyObserver(changer));
        Thread.ofPlatform().start(changer);
        obs1.join();
        obs2.join();
    }
}
 */

/**
import java.util.Random;
class Dekorator{
    public static void main(String[] args){
        test(new CounterDecoration(new GetSet()));
        test(new CounterDecoration(new SlowdownDecoration(new GetSet(), 5, 5)));
    }

    private static void test(CounterDecoration getSet){
        long endAt = System.currentTimeMillis() + 1000;
        Random rnd = new Random();
        do{
            getSet.set((rnd.nextInt(1000) + getSet.get()) % 1000);
        }while(System.currentTimeMillis() < endAt);
        System.out.println("Wykonano łącznie " + (getSet.setCounter() + getSet.getCounter()) + " operacji");
    }
}
 */

/**
import javax.swing.*;
public class Window {
    private final JFrame window; // ramka
    private final JButton on; // przycisk
    private final JButton off; // przycisk
    private final JLabel label; // etykieta

    public Window() {
        revealThread("Konstruktor");
        window = new JFrame();
        on = new JButton("ON");
        off = new JButton("OFF");
        label = new JLabel("n/a");
        window.setTitle("Okno testowe"); // nazwa okienka
        window.setSize(500, 500); // rozmiar okna
        addComponents();
        setActionListeneres();
        window.setVisible(true); // niech się wyświetli
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // zamknięcie okna = wyłączenie aplikacji
    }

    private void addComponents(){
        window.add(BorderLayout.WEST, on);
        window.add(BorderLayout.EAST, off);
        window.add(BorderLayout.SOUTH, label);
        window.add(BorderLayout.CENTER, new Panel());
    }
}
 */

/**
import javax.swing.*;
class Panel extends JPanel {
    private static final long serialVersionUID = -4700398944511177472L;
    private int x, y;
    private int xc, yc;

    public void paintComponent(Graphics g) {
        revealThread("paintComponent");
        g.setColor(Color.orange); // ustawienie koloru
        g.fillRect(0, 0, x, y); // wypełniony prostokąt
        g.setColor(Color.black);
        g.fillRect(x, 0, getWidth(), y);
        g.fillRect(0, y, x, getHeight());
        g.fillRect(x, y, getWidth(), getHeight());
        g.setColor(Color.yellow);
        g.drawLine(0, yc, getWidth(), yc); // linia
        g.drawLine(xc, 0, xc, getHeight());
        super.paintComponents(g);
    }
}
 */

/**
Panel() {
    addMouseMotionListener(new MouseMotionListener() {
        public void mouseMoved(MouseEvent e) {
            revealThread("mouseMoved");
            xc = e.getX(); // pozycja wskaźnika myszki
            yc = e.getY();
            repaint(); // zlecenie przerysowania
        }

        public void mouseDragged(MouseEvent e) {
            revealThread("mouseDragged");
            xc = x = e.getX();
            yc = y = e.getY();
            repaint();
        }
    });
}
*/

/**
private void setActionListeners(){
    on.addActionListeners((1) -> {
        label.setText("Uruchomiono");
        sleep(5000);
    });
    off.addActionListeners((1) -> label.setText("Wyłączono"));
}
 */

/**
public static void main(String[] args) {
    revealThread("Main");
    SwingUtilities.invokeLater(Window::new);
}

private static void revealThread(String txt) {
    System.out.println(txt + " wykonuje: " +
            Thread.currentThread().getName());
}

private static void sleep(long msec) {
    try {
        Thread.sleep(msec);
    } catch (InterruptedException e) {}
}
 */

/**
import java.sql.*;

class CreateInsertSelect {
    public static void main(String[] args) throws Exception {
        try {
            // rejestracja sterownika
            Class.forName("org.sqlite.JDBC");
        } catch (ClassNotFoundException e) {
            return;
        }

        // nawiązanie połączenie z bazą danych - to baza plikowa
        try (Connection con = DriverManager.getConnection(
                "jdbc:sqlite://tmp/sample.db");
             Statement stmt = con.createStatement();) {
            createTable(stmt);
            // pobieranie danych z bazy - studenci o imieniu kończącym się literą 'a'
            ResultSet rs = stmt.executeQuery(
                    "SELECT * FROM Studenci WHERE imie like '%a'");
            showResult(rs);
        }
    }

    // wykonanie polecenia na bazie
    private static void exec(Statement st, String SQL) throws SQLException {
        System.out.println(SQL + " -> " + st.executeUpdate(SQL));
    }

    private static void createTable(Statement st) throws SQLException {
        // kasujemy jeśli tabelka miasta istniała
        exec(st, "drop table if exists Studenci");
        // tworzymy przykładową tabelę
        exec(st,
                "create table Studenci " +
                        "(usosID integer,imie string,nazwisko string,email string)");
        // wprowadzamy dane
        exec(st, "INSERT INTO Studenci VALUES " +
                "(10101,'Jan','Kowalski','j.kowalski@student.uj.edu.pl')");
        exec(st, "INSERT INTO Studenci VALUES " +
                "(10234,'Maria','Nowak','m.nowak@student.uj.edu.pl')");
        exec(st, "INSERT INTO Studenci VALUES " +
                "(10344,'Anna','Matuszewska','anna.matuszewska@student.uj.edu.pl')");
        exec(st, "INSERT INTO Studenci VALUES " +
                "(12112,'Wacław','Wiśniewski','walerian.wisniewski@student.uj.edu.pl')");

        // poprawka dla jednego z rekodów
        exec(st, "UPDATE Studenci SET imie='Walerian' WHERE usosID=12112");
    }

    private static void showResult(ResultSet rs) throws SQLException {
        while (rs.next()) { // przemieszczanie kursora
            System.out.println("wiersz = " + rs.getRow());
            System.out.println(" - usosid   = " + rs.getInt("usosID") + " ");
            System.out.println(" - imie     = " + rs.getString("imie"));
            System.out.println(" - nazwisko = " + rs.getString("nazwisko"));
            System.out.println(" - email    = " + rs.getString("email"));
        }
    }
}
 */

/**
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;

public class Time {
    public static void main(String[] args) throws Exception {
        String server = "time-A.timefreq.bldrdoc.gov";
        int port = 13;

        String line;
        try (Socket so = new Socket(server, port);
             BufferedReader br = new BufferedReader(
                     new InputStreamReader(
                             so.getInputStream()))) {
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        }
    }
}
 */

/**
import java.net.*;
import java.io.*;
import java.util.stream.*;
public class TCPServer {
    public static void main(String[] args) throws Exception {
        int port = 8888;
        String address = "localhost";

        ServerSocket srvSck = new ServerSocket(port, 8192,
                InetAddress.getByName(address));

        while (true) {
            Socket socket = srvSck.accept();
            PrintWriter out = new PrintWriter(socket.getOutputStream());

            Thread.ofPlatform().start(() -> {
                IntStream.range(1, 11).forEach(i -> {
                    out.println("Hello World!!! " + i);
                    out.flush();
                });
                out.close();
            });
        }
    }
}
 */

/**
import java.net.*;
import java.io.*;
public class WWW {
    public static void main(String[] args) throws Exception {
        URI uri = new URI("https://www.uj.edu.pl/");
        URL url = uri.toURL();

        BufferedReader in = new BufferedReader(
                new InputStreamReader(
                        url.openConnection().getInputStream()));

        String s;

        while ((s = in.readLine()) != null) {
            System.out.println("> " + s);
        }
        in.close();
    }
}
 */

/**
abstract class NadKlasa {
    public void show() { System.out.println("show z NadKlasa"); }
    abstract void show(int i);
    abstract void show(double i);
}

abstract class PodKlasa extends NadKlasa {
    public void show(int i) { System.out.println("show z PodKlasa i = " + i); }
}

class Konkret extends PodKlasa {
    public void show(double i) { System.out.println("show z Konkret i = " + i); }

    public static void main(String[] args){
        Konkret ref = new Konkret();
        ref.show(1);
    }
}
 */

/**
interface Secure {}

class KlasaImplementujaca implements Secure {
    KlasaImplementujaca(){
        System.out.println("Tutaj konstruktor klasy implementującej");
    }
    public void cokolwiek() { System.out.println("Bla Bla Bla.."); }
}

class Main{
    public static void main(String[] args){
        KlasaImplementujaca ref = new KlasaImplementujaca();
        ref.cokolwiek();
    }
}
 */

/**
class Czlowiek {
    { System.out.println("Czlowiek: blok niestatyczny "); }
    public Czlowiek() { System.out.println("Czlowiek()"); }
}

class Pracownik extends Czlowiek {
    { System.out.println("Pracownik: blok niestatyczny "); }
    public Pracownik() { System.out.println("Pracownik()"); }

    public Pracownik(String du, String n, String st) {
        this();                     // wywołanie konstruktora bezparametrowego
        System.out.println("Pracownik (3x String)");
    }
}

class Main{
    public static void main(String[] args){
        String aa = "aaa"; String bb = "bbb"; String cc = "ccc";
        Pracownik ref1 = new Pracownik(aa, bb, cc);
        //ref.Pracownik(aa, bb, cc);
        //Pracownik ref2 = new Pracownik();
    }
}
 */

/**
class Zewnetrzna {
    private static int i = 10;

    static class Wewnetrzna {
        private static int j = 100;
        public int getI() { return i; }          // dostęp do statycznego pola klasy zewnętrznej
        public int getJ() { return j; }
    }
}

class Main{
    public static void main(String[] args){
        Zewnetrzna.Wewnetrzna ref = new Zewnetrzna.Wewnetrzna();
        System.out.println(ref.getI());
        System.out.println(ref.getJ());
    }
}
 */

/**
class Migacze {
    interface Miganie { void migaj(); }
    static class MigaczPrawy implements Miganie { public void migaj() { System.out.println("Prawy: miga"); } }
    static class MigaczLewy implements Miganie { public void migaj() { System.out.println("Lewy: miga"); } }
}

class Main{
    public static void main(String[] args){
        Migacze.MigaczPrawy ref1 = new Migacze.MigaczPrawy();
        Migacze.MigaczLewy ref2 = new Migacze.MigaczLewy();
        ref1.migaj();
        ref2.migaj();
    }
}
 */

/**
class Start {
    public static void test(Gadacz g) { g.mow("ciag testowy"); }

    public static void main(String[] argv) {
        test(new Gadacz("AnonimowyGadacz") {
            void mow(String s) {
                System.out.println(nazwa + " > " + s);
            }
        });
    }
}
abstract class Gadacz {
    String nazwa;
    public Gadacz(String n) {
        System.out.println("Konstruktor Gadac-a");
        nazwa = n;
    }
    abstract void mow(String tekst);
}
 */

/**
class Start {
    public static <T> T loopback(T ref) { return ref; }
    public <T> T nonStaticLoopback(T ref) { return ref; }

    public static void main(String[] argv) {
        String s = Start.<String>loopback("Ala ma kota");
        s = loopback("Ala ma kota");
        Start st = new Start();
        s = st.<String>nonStaticLoopback("Ala ma mysz");
        Object o = st.nonStaticLoopback(new Integer(1));
    }
}
*/

/**
import java.io.*;
import java.net.*;

public class Time {
    public static void main(String[] args) throws Exception {
        String server = "time-A.timefreq.bldrdoc.gov";
        int port = 13;
        try (Socket so = new Socket(server, port);
             BufferedReader br = new BufferedReader(
                     new InputStreamReader(so.getInputStream()))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        }
    }
}
 */

/**
import java.lang.ref.*;
import java.util.*;
public class Weak {
    private static Map<Integer, Reference<Circle>> cache = new HashMap<>();

    private static Circle betterGet(int radius) {
        Reference<Circle> ref = cache.get(radius);
        Circle result = (ref == null) ? null : ref.get();

        if (result == null) {
            System.out.println("Tworzę nowy obiekt Circle o promieniu " + radius);
            result = new Circle(radius);
            cache.put(radius, new WeakReference<>(result));
        }
        return result;
    }

    record Circle(int radius) {}
}
 */

/**
class A {
    static void show() {
        System.out.println("A");
    }
}

class B extends A {
    static void show() {
        System.out.println("B");
    }
}

class Test {
    public static void main(String[] args) {
        A obj = new B();
        obj.show();
    }
}
 */

/**
class Main {
    public static void main(String[] args) {
        Thread mth = new MyThread();
        mth.start();
        for (int i = 0; i < 100; i++)
            threadCallingCard();
    }

    public static void threadCallingCard() {
        System.out.println(Thread.currentThread().getName());
    }
}

class MyThread extends Thread{
    public void run() {
        for (int i = 0; i < 100; i++)
            Main.threadCallingCard();
    }
}
 */

/**
class Wspoldzielenie {
    public static void main(String[] args) throws InterruptedException {

        ObiektDoWspoldzielenia obiekt = new ObiektDoWspoldzielenia();

        Thread th = new Thread(new Runnable() {  // klasa anonimowa
            public void run() {
                obiekt.pole = 123;
            }
        });

        th.start();  // uruchom watek
        th.join();   // czekaj az sie zakonczy
        // join() pozwala zobaczyc zmiane pola
        System.out.println(obiekt.pole);
    }
}

class ObiektDoWspoldzielenia {
    int pole;  // pole, ktorego wartosc moga zmieniac watki
}
 */

/**
class Licznik {
    int wartosc = 0;

    public void zwieksz() {
        wartosc++;  // NIE jest atomowe!
        // W rzeczywistości to:
        // 1. Odczytaj wartosc
        // 2. Dodaj 1
        // 3. Zapisz wynik
    }
}

class Test {
    public static void main(String[] args) throws InterruptedException {
        Licznik licznik = new Licznik();

        // 1000 wątków, każdy dodaje 1
        Thread[] watki = new Thread[1000];
        for (int i = 0; i < 1000; i++) {
            watki[i] = new Thread(() -> licznik.zwieksz());
            watki[i].start();
        }

        // Czekaj na wszystkie
        for (Thread t : watki) t.join();

        System.out.println(licznik.wartosc);  //Może być < 1000 !
    }
}
 */
