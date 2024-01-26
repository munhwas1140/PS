use std::collections::VecDeque;
use std::io;
use io::Write;

fn dfs(now: usize, g: &Vec<Vec<usize>>, ans: &mut Vec<usize>, visited: &mut Vec<bool>, cnt: &mut usize) {
    visited[now] = true;
    ans[now] = *cnt;
    *cnt += 1;
    for &next in &g[now] {
        if visited[next] == false {
            dfs(next, g, ans, visited, cnt);
        }
    }
}

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

    let mut g: Vec<Vec<usize>> = vec![vec![]; n + 1];

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

        g[t1].push(t2);
        g[t2].push(t1);
    }

    for i in 1..=n {
        g[i].sort();
    }
    
    let mut visited = vec![false; n + 1];
    let mut ans: Vec<usize> = vec![0; n + 1];
    let mut cnt = 1;
    dfs(s, &g ,&mut ans, &mut visited, &mut cnt);

    let mut out = io::BufWriter::new(io::stdout().lock());
    for i in 1..=n {
        writeln!(out, "{}", ans[i]).unwrap();
    }
}