while true {
  let input = readLine()!
    .split(separator: " ")
    .map { Int($0)! }

  let (a, b) = (input[0], input[1])
  if a != 0 || b != 0 {
    print(a + b)
  } else {
    break
  }
}
