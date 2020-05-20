fn fibonacci(n: i32) -> i32 {
    if n <= 1 {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let val = line.trim_end().parse().unwrap();
    println!("{}", fibonacci(val));
}
