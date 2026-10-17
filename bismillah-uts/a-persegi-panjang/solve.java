import java.util.*;

class PersegiPanjang {
    private double panjang;
    private double lebar;

    public PersegiPanjang(double p, double l) {
        panjang = p;
        lebar = l;
    }

    public double luas() {
        return panjang * lebar;
    }

    public double keliling() {
        return 2 * (panjang + lebar);
    }
}

public class solve {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        double panjang, lebar;
        for (int i = 0; i < n; i++) {
            panjang = sc.nextDouble();
            lebar = sc.nextDouble();

            PersegiPanjang P = new PersegiPanjang(panjang, lebar);
            System.out.printf(
                    java.util.Locale.US,
                    "%.2f %.2f\n", P.luas(), P.keliling());
        }

    }
}
