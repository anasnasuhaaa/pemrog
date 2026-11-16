
# 11C. Sub List

| Time Limit | Memory Limit |
|------------|--------------|
| 2 s        | 256 MB       |

## Deskripsi

Diketahui N pasangan list A dan B yang masing-masing berisi bilangan bulat. Buatlah program fungsional Scala untuk memeriksa apakah list A merupakan sub list dari list B dengan menggunakan **fungsi rekursif**.

## Constraints

- **Style:** Pemrograman fungsional.
- **Dilarang:** `var`, `while`, `for` imperatif, `forall`, dan mutasi data kecuali pada proses membaca input data.
- **Wajib:** Fungsi murni (*pure function*), Higher-Order Function (HOF), struktur data dan container, serta fungsi rekursif.

## Format Input

Input data diberikan dengan format:

```text
N A1 A2 … AN B1 B2 … BN … … A1 A2 … AN B1 B2 … BN
```

## Format Output

Sebanyak N baris teks `YA` atau `TIDAK`.

## Sample Input

```text
3 2 3 4 1 2 3 4 5 1 2 1 2 3 4 5 1 3 4 1 2 3 4 5
```

## Sample Output

```text
YA
YA
TIDAK
```
