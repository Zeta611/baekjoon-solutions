let number = Int(readLine()!)!
let input = readLine()!
  .split(separator: " ")
  .map { Int($0)! }
print(input.min()!, input.max()!)
// let (min_, max_) = readLine()!
//   .split(separator: " ")
//   .reduce((Int.max, Int.min)) {(min($0.0, Int($1)!), max($0.1, Int($1)!))}
// print(min_, max_)
