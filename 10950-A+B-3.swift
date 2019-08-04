let numberOfCases = Int(readLine()!)!
for _ in 0..<numberOfCases {
  print(
    readLine()!
      .split(separator: " ")
      .map { Int($0)! }
      .reduce(0, +))
}
