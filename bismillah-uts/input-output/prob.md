# Average of Four Integers

## Description

In this challenge, you are required to read four integer values and compute their average. Your solution must output the average with exactly two decimal places.

*Example:* Variables such as *a*, *b*, *c*, and *d* are provided as input, and the output should be formatted as `3.25` if the average is 3.25.

## Input Format

A single line containing four space-separated integers:

```text
a b c d
```

## Constraints

- -100,000,000 < *a*, *b*, *c*, *d* < 100,000,000

## Output Format

Print a single line containing the average of the four integers, formatted to two decimal places.

*Example:* If the average is 3.25, the output must be exactly `3.25`.

## Sample Input 0

```text
1 3 4 5
```

## Sample Output 0

```text
3.25
```

## Explanation 0

The average is calculated as follows:

\[
\text{Average} = \frac{a+b+c+d}{4}
\]

For the sample input, the computation is:

\[
\text{Average} = \frac{1+3+4+5}{4}
\]

\[
= \frac{13}{4} = \boxed{3.25}
\]

Therefore, the output is `3.25`.