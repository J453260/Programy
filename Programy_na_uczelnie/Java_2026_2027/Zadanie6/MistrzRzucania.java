public class MistrzRzucania implements Rzucanie{
    public FabrykaJabłek fabryka;
    public Rzucacz rzucacz;
    public Rzucacz.Zakres zakresKatow;
    public Rzucacz.Zakres zakresSily;

    public double katMin;
    public double katMax;
    public double silaMin;
    public double silaMax;

    public void pobieranieJabłek(FabrykaJabłek fabryka ){
        this.fabryka = fabryka;
    }

    public void rzucaczJabłek( Rzucacz rzucacz ){
        this.rzucacz = rzucacz;

        zakresKatow = rzucacz.zakresKątów();
        zakresSily = rzucacz.zakresSiłyRzutu();
    }

    public void rzucaj() {
        katMin = zakresKatow.min();
        katMax = zakresKatow.max();
        silaMin = zakresSily.min();
        silaMax = zakresSily.max();

        Jablko jablko;
        while (true) {
            try{
               jablko = fabryka.pobierzJabłko();
            } catch (BrakJabłekException e){
                break;
            }

            double kat = (katMin + katMax) / 2;
            double sila = (silaMin + silaMax) / 2;

            try{
                rzucacz.rzut(jablko, kat, sila);
            } catch (ZaBliskoException e){
                silaMin = sila;
            } catch (ZaDalekoException e){
                silaMax = sila;
            } catch (ZbytWLewoException e){
                katMin = kat;
            } catch (ZbytWPrawoException e){
                katMax = kat;
            }
        }
    }
}