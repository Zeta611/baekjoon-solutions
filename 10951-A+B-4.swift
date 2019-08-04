while let input = readLine() {
  print(input
    .split(separator: " ")
    .map { Int($0)! }
    .reduce(0, +))
}
