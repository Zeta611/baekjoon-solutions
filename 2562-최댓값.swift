var max = 0
var maxIndex = 0
var index = 0
while let n = readLine() {
  index += 1
  if Int(n)! > max {
    max = Int(n)!
    maxIndex = index
  }
}
print(max)
print(maxIndex)
