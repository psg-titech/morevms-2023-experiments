function [] = showhist(n)
   fd = mopen(n, 'rb');
   d = mget(120000, 'i', fd)/50;
   printf("max:%f", max(d));
   histplot(50, d);
   mclose(fd);
endfunction

men = mopen('emfrp-node1.dat', 'rb');
en = mget(120000, 'i', men);
mclose(men);
mean(en/50) // => 3.3862688
sum(3.35<=(en/50) & (en/50)<=3.43)/length(en) // => 0.995875

men = mopen('emfrp-tuple.dat', 'rb');
et = mget(120000, 'i', men);
mclose(men);
mean(et/50) // => 3.6399120
sum(3.6<=(et/50) & (et/50)<= 3.66)/length(et) // => 0.996

men = mopen('emfrp-multinode.dat', 'rb');
emn = mget(120000, 'i', men);
mclose(men);
mean(emn/50) // => 7.3086967
sum(7.26<=(emn/50) & (emn/50)<= 7.34)/length(emn) // => 0.9954333


men = mopen('emfrp-repl-onenode.dat', 'rb');
eron = mget(120000, 'i', men);
mclose(men);
mean(eron/50) // => 9.9785238
sum(9.50<=(eron/50) & (eron/50)<= 10.4)/length(eron) // => 0.996075

men = mopen('MicroPython-direct.dat', 'rb');
mpd = mget(120000, 'i', men);
mclose(men);
mean(mpd/50) // => 38.867721
sum(38.4<=(mpd/50) & (mpd/50)<= 39.3)/length(mpd) // => 0.9853333

men = mopen('emfrp-repl-tuple.dat', 'rb');
mrt = mget(120000, 'i', men);
mclose(men);
histplot(50, mrt/50, normalization=%f);
xlabel('Latency [Microseconds]');
ylabel('Frequency [Iterations]');
title('Histogram of latencies of Emfrp-REPL (Tuple)');
xpoly([max(mrt)/50, max(mrt)/50], [0, 80000]);
set(gce(), "foreground", color("red"), "closed", "on");
xstring(55, 65000, ["max. = " ; "67.4 [us]"]);
gcf().figure_size = [400, 400];
xs2svg(0, 'emfrp-tuple-fig');

men = mopen('MicroPython-tuple.dat', 'rb');
mpt = mget(120000, 'i', men);
mclose(men);
//mpt_s = gsort(mpt) / 50;
//histplot(50, mpt_s(39:120000), normalization=%f);
histplot(50, mpt/ 50, normalization=%f);
xlabel('Latency [Microseconds]');
ylabel('Frequency [Iterations]');
title('Histogram of latencies of MicroPython (Tuple)');
xpoly([max(mpt)/50, max(mpt)/50], [0, 22000]);
set(gce(), "foreground", color("red"), "closed", "on");
xstring(2000, 18000, ["max. = " ; "2.4 [ms]"]);
gcf().figure_size = [400, 400];
xs2svg(0, 'MicroPython-tuple-fig');


men = mopen('emfrp-repl-multinode.dat', 'rb');
ermn = mget(120000, 'i', men);
mclose(men);
histplot(50, ermn / 50, normalization=%f);
xlabel('Latency [Microseconds]');
ylabel('Frequency [Samples]');
title('Histogram of latencies of Emfrp-REPL (10 nodes)');
gcf().figure_size = [400, 400];
xs2svg(0, 'emfrp-repl-multinode-fig');
