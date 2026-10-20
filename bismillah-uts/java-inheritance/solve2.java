import java.util.*;

abstract class Ruang2D {
    public abstract double hitungLuas();

    public abstract double hitungKeliling();
}

class Segiempat extends Ruang2D {
    private double panjang;
    private double lebar;

    Segiempat(double p, double l) {
        panjang = p;
        lebar = l;
    }

    @Override
    public double hitungLuas() {
        return panjang * lebar;
    }

    @Override
    public double hitungKeliling() {
        return 2 * (panjang + lebar);
    }

}

class Segitiga extends Ruang2D {
    private double alas;
    private double tinggi;

    Segitiga(double a, double t) {
        alas = a;
        tinggi = t;
    }

    @Override
    public double hitungLuas() {
        return 0.5 * alas * tinggi;
    }

    @Override
    public double hitungKeliling() {
        return alas + tinggi + Math.sqrt(Math.pow(alas, 2) + Math.pow(tinggi, 2));
    }

}

public class solve2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char tipe;

        double total_luas_segiempat = 0.0;
        double total_luas_segitiga = 0.0;

        double total_kel_segiempat = 0.0;
        double total_kel_segitiga = 0.0;

        while ((tipe = scanner.next().charAt(0)) != 'X') {

            int a = scanner.nextInt();
            int b = scanner.nextInt();

            if ((tipe) == 'R') {
                Segiempat S = new Segiempat(a, b);
                total_luas_segiempat += S.hitungLuas();
                total_kel_segiempat += S.hitungKeliling();
            } else if ((tipe) == 'T') {
                Segitiga S = new Segitiga(a, b);
                total_luas_segitiga += S.hitungLuas();
                total_kel_segitiga += S.hitungKeliling();
            }
        }

        System.out.println("LUAS");
        System.out.printf("- Segiempat : %.2f\n", total_luas_segiempat);
        System.out.printf("- Segitiga : %.2f\n", total_luas_segitiga);
        System.out.println("KELILING");
        System.out.printf("- Segiempat : %.2f\n", total_kel_segiempat);
        System.out.printf("- Segitiga : %.2f\n", total_kel_segitiga);

    }
}