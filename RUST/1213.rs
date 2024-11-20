use std::io::stdin;

fn main() {
	let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

    let mut a = vec![0; 26];
    for c in input.trim().chars() {
        let now = (c as u8 - 'A' as u8) as usize;
        a[now] += 1;
    }

    let mut idx = -1;
    let mut cnt = 0;

    for i in 0..26 {
        if a[i] % 2 != 0 {
            cnt += 1;
            idx = i as i32;
            if cnt == 2 {
                print!("I'm Sorry Hansoo");
                return;
            }
        }
    }

    for i in 0..26 {
        for _ in 0..(a[i] / 2) {
            print!("{}", (i as u8 + 'A' as u8) as char)
        }
    }

    if idx != -1 {
        print!("{}", (idx as u8 + 'A' as u8) as char)
    }

    for i in (0..26).rev() {
        for _ in 0..(a[i] / 2) {
            print!("{}", (i as u8 + 'A' as u8) as char)
        }
    }
}