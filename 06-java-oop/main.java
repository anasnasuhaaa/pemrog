import java.util.Scanner;
class InputOutput {
  public static void main(String[] args) {
    Scanner inp = new Scanner(System.in);
    int a = inp.nextInt();
    double b = inp.nextDouble();
    double res = a + b;
    System.out.printf("Hasil = %.2f\n", res);
    inp.close();
  }
}