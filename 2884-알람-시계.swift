let input = readLine()!
  .split(separator: " ")
  .map { Int($0)! }

let (hour, minutes) = (input[0], input[1])

if minutes >= 45 {
  print("\(hour) \(minutes - 45)")
} else if hour > 0 {
  print("\(hour - 1) \(minutes + 15)")
} else {
  print("23 \(minutes + 15)")
}
