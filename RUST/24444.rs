use std::io::{self, Write};
use std::collections::VecDeque;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();

    let (n, m, s) = {
        let v = buf
            .split_whitespace()
            .map(|x| x.trim().parse::<usize>().unwrap())
            .collect::<Vec<_>>();
        (v[0], v[1], v[2])
    };

    let mut g = vec![vec![]; n + 1];

    for _ in 0..m {
        buf.clear();
        io::stdin().read_line(&mut buf).unwrap();
        
        let (t1, t2) = {
            let v = buf
                .split_whitespace()
                .map(|x| x.trim().parse::<usize>().unwrap())
                .collect::<Vec<_>>();
            (v[0], v[1])
        };

        // println!("t1 = {t1}, t2 = {t2}");

        g[t1].push(t2);
        g[t2].push(t1);
    }

    for i in 0..=n {
        g[i].sort();
    }


    let mut q = VecDeque::new();
    let mut ans = vec![0; n + 1];
    let mut visited = vec![false; n + 1];
    let mut cnt = 1;

    visited[s] = true;
    q.push_back(s);

    
    while q.len() != 0 {
        let now = q.pop_front().unwrap();
        ans[now] = cnt;
        cnt += 1;

        for &next in &g[now] {
            // println!("next is {next}");
            if visited[next] == false {
                visited[next] = true;
                q.push_back(next);
            }
        }
    }


    let mut out = io::BufWriter::new(io::stdout().lock());
    for i in 1..=n {
        writeln!(out, "{}", ans[i]);
    }
}