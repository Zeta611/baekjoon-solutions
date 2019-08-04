var result = Set<Int>()
while let n = readLine() {
  result.insert(Int(n)!%42)
}
print(result.count)
// print(Set((0...9).map{_ in Int(readLine()!)!%42}).count)
