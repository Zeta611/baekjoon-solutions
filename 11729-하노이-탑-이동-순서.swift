import Foundation

func hanoi(n: Int, from source: Int, to dest: Int) {
  if n == 1 {
    print(source, dest)
    return
  }
  hanoi(n: n - 1, from: source, to: 6 - source - dest)
  hanoi(n: 1, from: source, to: dest)
  hanoi(n: n - 1, from: 6 - source - dest, to: dest)
}

let n = Int(readLine()!)!
print(pow(2, n) - 1)
hanoi(n: n, from: 1, to: 3)
