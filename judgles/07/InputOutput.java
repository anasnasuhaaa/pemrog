import java.util.*;

public class InputOutput {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    sc.useLocale(Locale.US);

    int n = sc.nextInt();

    double[] nilai = new double[n];

    double min = Double.MAX_VALUE;
    double max = -Double.MAX_VALUE;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
      nilai[i] = sc.nextDouble();

      if (nilai[i] < min) {
        min = nilai[i];
      }

      if (nilai[i] > max) {
        max = nilai[i];
      }

      sum += nilai[i];
    }

    double mean = sum / n;

    double jumlahKuadratSelisih = 0.0;

    for (int i = 0; i < n; i++) {
      double selisih = nilai[i] - mean;
      jumlahKuadratSelisih += selisih * selisih;
    }

    double stdDev;

    if (n == 1) {
      stdDev = 0.0;
    } else {
      stdDev = Math.sqrt(jumlahKuadratSelisih / (n - 1));
    }

    System.out.printf("%.2f %.2f%n", min, max);
    System.out.printf("%.2f %.2f%n", mean, stdDev);

    sc.close();
  }
}