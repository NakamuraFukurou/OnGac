OnGac
=====

Arduinoで電子スピーカをつなげて鳴らす時の配列を作成するプログラム

## 音楽作成用のテキストファイルを作る
(*.txt)ファイルに| 音があるか | 音階名 | 高さ | 長さ |の順で入れる

[sample.txt](https://github.com/NakamuraFukurou/OnGac/blob/master/sample.txt)

## arduino用に変換する

これをコンパイルしたOnGac.exe, OnGac.oにドラッグ＆ドロップすると、ディレクトリ内に[sample.notes](https://github.com/NakamuraFukurou/OnGac/blob/master/sample.notes)ができる

## 実際に使ってみる
ここで作成したファイルを[sample.ino](https://github.com/NakamuraFukurou/OnGac/blob/master/sample/sketch_nov20a.ino)のように使うと、音を奏でることができます
