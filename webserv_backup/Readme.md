recv bytes → accumulate into raw_request until \r\n\r\n found (headers only)
headers complete → parse Content-Length (B's job, but you need it to know when body is done)
create temp file → open it, get fd
every subsequent recv() → write bytes directly to that file instead of a string
track bytes written vs Content-Length
when bytes written == Content-Length → body complete → hand fd to C