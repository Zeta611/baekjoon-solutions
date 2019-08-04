let numberOfCases = Int(readLine()!)!
for i in 1...numberOfCases {
  print("Case #\(i): ", terminator: "")
  let input = readLine()!
    .split(separator: " ")
  print(input.joined(separator: " + "), "=", terminator: " ")
  print(input
    .map{ Int($0)! }
    .reduce(0, +))
}
// (1...Int(readLine()!)!).map{let a=readLine()!.split{$0==" "}.map{Int($0)!}
// print("Case #\($0): \(a[0]) + \(a[1]) = \(a[0]+a[1])")}
