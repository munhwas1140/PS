use std::io;

fn month_to_int(m: &str) -> i32 {
    match m {
        "January" => 1,
        "February" => 2,
        "March" => 3,
        "April" => 4,
        "May" => 5,
        "June" => 6,
        "July" => 7,
        "August" => 8,
        "September" => 9,
        "October" => 10,
        "November" => 11,
        "December" => 12,
        _ => -1,
    }
}

fn sum_day(month: i32, year: i32) -> i32 {
    let days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let mut ret = 0;
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) && month >= 2 {
        ret += 1;
    }

    for i in 1..=month as usize {
        ret += days[i];
    }
    ret
}

fn year_min(year: i32) -> i32 {
    sum_day(12, year) * 60 * 24
}

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();

    let (m, d, y, t) = {
        let v = buf
            .split_whitespace()
            .map(|x| x.trim())
            .collect::<Vec<_>>();
        (v[0], v[1], v[2], v[3])
    };


    let tmp = d.to_string();
    d = &d[0..2];
    let day: i32 = d.parse().unwrap();


    let month = month_to_int(m);

    let year: i32 = y.parse().unwrap();

    let min = {
        let v: Vec<i32> = t
        .split(':')
        .map(|x| x.parse().unwrap())
        .collect::<Vec<i32>>();
        (sum_day(month - 1, year) + day - 1) * 60 * 24 + v[0] * 60 + v[1]
    };

    print!("{}\n", min as f64 * 100.0 / year_min(year) as f64);

}