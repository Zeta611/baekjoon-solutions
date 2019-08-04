let numberOfCases = Int(readLine()!)!
for i in 1...numberOfCases {
  print("Case #\(i): ", terminator: "")
  print(
    readLine()!
      .split(separator: " ")
      .map { Int($0)! }
      .reduce(0, +))
}
