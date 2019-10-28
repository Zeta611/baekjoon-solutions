var coords = (x: [Int](), y: [Int]())
for _ in 0..<3 {
  let input = readLine()!.split { $0 == " " }.map { Int($0)! }
  coords.x.append(input[0])
  coords.y.append(input[1])
}
coords.x.sort()
coords.y.sort()
print(
  coords.x.reduce(0, +) - 2 * coords.x[1],
  coords.y.reduce(0, +) - 2 * coords.y[1])
