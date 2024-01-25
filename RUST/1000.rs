use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let a = input.next().unwrap();
    let b = input.next().unwrap();
    println!("{}", a + b);

}