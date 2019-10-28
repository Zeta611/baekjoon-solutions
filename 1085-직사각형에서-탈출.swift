let input = readLine()!.split { $0 == " " }.map { Int($0)! }
let (x, y, w, h) = (input[0], input[1], input[2], input[3])
print(min(x, y, w - x, h - y))
