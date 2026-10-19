
import java.util.Scanner;

abstract class Pegawai {
    protected String identitasPegawai;

    public Pegawai(String id) {
        this.identitasPegawai = id;
    }

    public abstract int gajiBulanan();

    public String getIdentitasPegawai() {
        return identitasPegawai;
    }
}

class PegawaiTetap extends Pegawai {
    private int gajiPokok;
    private int tunjangan;

    public PegawaiTetap(String id, int gp, int tj) {
        super(id);
        this.gajiPokok = gp;
        this.tunjangan = tj;
    }

    @Override
    public int gajiBulanan() {
        return gajiPokok + tunjangan;
    }
}

class PegawaiHarian extends Pegawai {
    private int jamKerja;

    public PegawaiHarian(String id, int jk) {
        super(id);
        this.jamKerja = jk;
    }

    @Override
    public int gajiBulanan() {
        if (jamKerja <= 200) {
            return jamKerja * 1000;
        } else if (jamKerja <= 250) {
            return 200 * 1000 + (jamKerja - 200) * 1500;
        } else {
            return 200 * 1000 + 50 * 1500;
        }
    }
}

public class solve {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Pegawai[] p = new Pegawai[n];

        for (int i = 0; i < n; i++) {
            int tipe = sc.nextInt();
            String id = sc.next();

            if (tipe == 1) {
                int gajiPokok = sc.nextInt();
                int tunjangan = sc.nextInt();

                p[i] = new PegawaiTetap(
                    id, gajiPokok, tunjangan
                );
            } else {
                int jamKerja = sc.nextInt();
                int tunjangan = sc.nextInt();

                p[i] = new PegawaiHarian(id, jamKerja);
            }
        }

        double totalGaji = 0;
        int maxGaji = -1;
        String idMaxGaji = "";

        for (int i = 0; i < n; i++) {
            int gaji = p[i].gajiBulanan();
            totalGaji += gaji;

            if (gaji > maxGaji) {
                maxGaji = gaji;
                idMaxGaji = p[i].getIdentitasPegawai();
            }
        }

        double rataRata = totalGaji / n;

        System.out.printf(
            java.util.Locale.US,
            "Rata-rata: %.2f%n", rataRata
        );
        System.out.println("Gaji Tertinggi: " + maxGaji);
        System.out.println(idMaxGaji);

        sc.close();
    }
}
