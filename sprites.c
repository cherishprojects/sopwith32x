/* Source code for Sopwith (sprite data)
   Reverse-engineered by Andrew Jenner

   Copyright (c) 1984-2000 David L Clark
   Copyright (c) 1999-2000 Andrew Jenner

   All rights reserved except as specified in the file license.txt.
   Distribution of this file without the license.txt file accompanying is
   prohibited.
*/

unsigned char bombsprites[2][8][16]={
  {{  0,  0,  0,  0, 81, 84, 85, 85, 85, 85, 81, 84,  0,  0,  0,  0},
   {  0,  0,  0, 84,  1, 85,  5, 85, 17, 84, 85, 16, 21, 64,  1,  0},
   {  1, 64,  5, 80,  5, 80,  5, 80,  5, 80,  1, 64,  5, 80,  5, 80},
   {  0,  0, 21,  0, 85, 64, 85, 80, 21, 68,  4, 85,  1, 84,  0, 64},
   {  0,  0,  0,  0, 21, 69, 85, 85, 85, 85, 21, 69,  0,  0,  0,  0},
   {  0, 64,  1, 84,  4, 85, 21, 68, 85, 80, 85, 64, 21,  0,  0,  0},
   {  5, 80,  5, 80,  1, 64,  5, 80,  5, 80,  5, 80,  5, 80,  1, 64},
   {  1,  0, 21, 64, 85, 16, 17, 84,  5, 85,  1, 85,  0, 84,  0,  0}},
  {{  0,  0,  0,  0,162,168,170,170,170,170,162,168,  0,  0,  0,  0},
   {  0,  0,  0,168,  2,170, 10,170, 34,168,170, 32, 42,128,  2,  0},
   {  2,128, 10,160, 10,160, 10,160, 10,160,  2,128, 10,160, 10,160},
   {  0,  0, 42,  0,170,128,170,160, 42,136,  8,170,  2,168,  0,128},
   {  0,  0,  0,  0, 42,138,170,170,170,170, 42,138,  0,  0,  0,  0},
   {  0,128,  2,168,  8,170, 42,136,170,160,170,128, 42,  0,  0,  0},
   { 10,160, 10,160,  2,128, 10,160, 10,160, 10,160, 10,160,  2,128},
   {  2,  0, 42,128,170, 32, 34,168, 10,170,  2,170,  0,168,  0,  0}}};

unsigned char buildingsprites[2][4][64]={
  {{  0,  0,  2,  0,  0,  0,  2, 85,  0,  0,  2, 85,  0,  0,  2,  0,
      0,  0,  2,  0,  0,  0,  2,  0,  0,  0,  2,  0, 85, 85, 85, 85,
     85, 85, 85, 85, 90,170,170,165, 89, 85, 85,101, 89, 85, 85,101,
     89, 85, 85,101, 89, 85, 85,101, 89, 85, 85,101, 89, 85, 85,101},
   {  0,  0, 10, 10,  0,  0, 10, 10,  0,  0, 10, 10, 85, 85, 90, 10,
     85, 85, 90, 10, 86,102, 90, 10, 85, 85, 85, 90, 86,102, 85, 90,
     85, 85, 85, 90, 86,102,102, 90, 85, 85, 85, 90, 86,102,102, 90,
     85, 85, 85, 90, 86,102,102, 90, 85, 85, 85, 90, 85, 85, 85, 90},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  1, 85, 85, 64, 21, 85, 85, 84, 85, 89,149, 85,
     85, 90,149, 85, 85, 89,149, 85, 85, 90,149, 85, 21, 89,149, 84,
      5, 90,149, 80, 10,  8,128,160, 10, 10,128,160, 10,  8,128,160},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 21, 84,  0,
      0, 21, 85, 85,  0, 21, 84,  0, 85, 85, 85, 85, 85, 85, 85, 85,
    106,170,170,169,149, 85, 85, 86,149, 85, 85, 86, 42,170,170,168}},
  {{  0,  0,  1,  0,  0,  0,  1,170,  0,  0,  1,170,  0,  0,  1,  0,
      0,  0,  1,  0,  0,  0,  1,  0,  0,  0,  1,  0,170,170,170,170,
    170,170,170,170,165, 85, 85, 90,166,170,170,154,166,170,170,154,
    166,170,170,154,166,170,170,154,166,170,170,154,166,170,170,154},
   {  0,  0,  5,  5,  0,  0,  5,  5,  0,  0,  5,  5,170,170,165,  5,
    170,170,165,  5,169,153,165,  5,170,170,170,165,169,153,170,165,
    170,170,170,165,169,153,153,165,170,170,170,165,169,153,153,165,
    170,170,170,165,169,153,153,165,170,170,170,165,170,170,170,165},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  2,170,170,128, 42,170,170,168,170,166,106,170,
    170,165,106,170,170,166,106,170,170,165,106,170, 42,166,106,168,
     10,165,106,160,  5,  4, 64, 80,  5,  5, 64, 80,  5,  4, 64, 80},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 42,168,  0,
      0, 42,170,170,  0, 42,168,  0,170,170,170,170,170,170,170,170,
    149, 85, 85, 86,106,170,170,169,106,170,170,169, 21, 85, 85, 84}}};

unsigned char debrissprites[2][64]={
  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4, 64,  0,  0,  5,
    80, 16,  2, 21, 81, 80, 82, 85, 85,165, 89, 85, 85,165,101, 85},
  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,128,  0,  0, 10,
   160, 32,  1, 42,162,160,161,170,170, 90,166,170,170, 90,154,170}};

unsigned char shrapnelsprites[8][16]={
  {252,128,252,128,254,  0, 10,149,162, 85,  1, 64,  1, 64,  1, 64},
  {  1, 64, 21, 84, 86,149, 90,165, 90,165, 86,149, 21, 84,  1, 64},
  {  0, 32,  0,168,  2,170, 10,168, 42,160,170,128, 42,  0,  8,  0},
  {  1, 64,  1, 80, 21, 84, 85, 85, 85, 85, 21, 68,  5, 64,  1, 64},
  { 26,128, 63, 80, 10,236,182,164,  0,  5, 24, 14,  7,  9,  6,  1},
  { 80,  0, 80, 96,  0,144,  0,  0,  0, 40, 40, 40, 40,  0,  0,  0},
  {  0,  0,  0,  5,  0,  5,  1, 64, 97, 64,144,  0,  0, 40,  0, 40},
  {  0,  0, 48, 48,  3,  0,  0, 12,204,  0,  0,195, 12,  0,  0, 12}};

unsigned char planesprites[2][2][16][64]={
  {{{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      84,  0,  0,  0, 85,  0,170,168, 85, 64,  8,128,170,149, 89,149,
      21, 85, 89,149,  5, 85,170,165,  4,  0,  1,  0,  0,  0,  5, 64,
       0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,160,
       0,  0, 42,  4,  0,  2,162, 85, 16,  0, 25,149, 84, 65, 89,160,
      85,149,106,  0,106, 85, 96, 80, 21, 84,  1, 64,  1, 64,  0,  0,
       1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  8,  0,  0,  0,  8, 64,  0,  0,161, 80,
       0,  2,  9, 80,  0,  8,166,128,  0,  0, 74,  0,  0,  1, 88, 80,
       0,  5, 96, 80, 17, 85, 64,  0, 85,149,  0,  0, 86, 84,  0,  0,
      25, 80,  0,  0,  0, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  4,  0,  0,  2,149, 64,  0,  2, 21,  0,  0,  8,166,  0,
       0,  8, 90,  0,  0, 10,169, 64,  0, 32, 88, 80,  0,  1, 96,  0,
       0,  1, 96,  0,  0,  5, 80,  0,  0, 21, 64,  0,  5,105, 64,  0,
       5,101,  0,  0, 21,101,  0,  0,  5,128, 64,  0,  0,  0,  0,  0},
    {  0,  1, 80,  0,  0, 33, 80,  0,  0, 33, 96,  0,  0, 42,161,  0,
       0, 33,101, 64,  0, 42,161,  0,  0, 33, 96,  0,  0, 33, 96,  0,
       0,  1, 80,  0,  0,  1, 80,  0,  0,  1, 80,  0,  0,  6, 80,  0,
       0, 22, 80,  0,  0, 86, 84,  0,  0, 86, 64,  0,  0, 86,  0,  0},
    {  0, 20,  0,  0,  0, 84,  0,  0,  2, 22, 16,  0,  2, 26, 20,  0,
       2,165,132,  0,  0,138,128,  0,  0,165,160,  0,  0, 33, 80,  0,
       0, 33, 80,  0,  0,  0, 84,  0,  0,  0, 84,  0,  0,  1,149,  0,
       0,  0,101, 64,  0,  1,100,  0,  0,  5,100,  0,  0,  1, 80,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  1, 65, 64,  0,  5, 97, 64,  0,
       1,104,  0,  0, 40,154,  0,  0,  2, 33,128,  0,  2, 37, 80,  0,
       0,129, 84,  0,  0, 32, 85,  0,  0,  0, 21, 80,  0,  0, 25, 64,
       0,  0, 22, 64,  0,  0,  5,128,  0,  0, 21, 64,  0,  0,  5,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0, 16, 20,  0,  0,
      22,144,  0,  0, 85,168,  0,  0, 22,102,144,  0, 34,101, 85,  4,
      40, 33, 85, 80,  2,160, 22, 80,  0,  8,  6,160,  0,  0,  1, 88,
       0,  0,  1, 84,  0,  0,  1, 84,  0,  0,  0, 16,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64,  0,  0,
       1, 80,  0,  0,  0, 64,  0, 16, 90,170, 85, 80, 86,101, 85, 84,
      86,101, 86,170,  2, 32,  1, 85, 42,170,  0, 85,  0,  0,  0, 21,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64,
       0,  0,  1, 64,  1, 64, 21, 84,  5,  9, 85,169,  0,169, 86, 85,
      10,101, 65, 21, 86,100,  0,  4, 85,138,128,  0, 16,168,  0,  0,
      10,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  5,100,
       0,  0, 21,149,  0,  0, 86, 85,  0,  1, 85, 68,  5,  9, 80,  0,
       5, 37, 64,  0,  0,161,  0,  0,  2,154, 32,  0,  5, 96,128,  0,
       5, 74,  0,  0,  1, 32,  0,  0,  0, 32,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  1,  2, 80,  0,  0, 89, 84,  0,  0, 89, 80,
       0,  1,105, 80,  0,  1, 84,  0,  0,  5, 80,  0,  0,  9, 64,  0,
       0,  9, 64,  0,  5, 37,  8,  0,  1,106,160,  0,  0,165, 32,  0,
       0,154, 32,  0,  0, 84,128,  0,  1, 86,128,  0,  0, 16,  0,  0},
    {  0,  0,149,  0,  0,  1,149,  0,  0, 21,149,  0,  0,  5,148,  0,
       0,  5,144,  0,  0,  5, 64,  0,  0,  5, 64,  0,  0,  5, 64,  0,
       0,  9, 72,  0,  0,  9, 72,  0,  0, 74,168,  0,  1, 89, 72,  0,
       0, 74,168,  0,  0,  9, 72,  0,  0,  5, 72,  0,  0,  5, 64,  0},
    {  0,  5, 64,  0,  0, 25, 80,  0,  0, 25, 64,  0,  1, 89,  0,  0,
       0, 86, 64,  0,  0, 21,  0,  0,  0, 21,  0,  0,  0,  5, 72,  0,
       0,  5, 72,  0,  0, 10, 90,  0,  0,  2,162,  0,  0, 18, 90,128,
       0, 20,164,128,  0,  4,148,128,  0,  0, 21,  0,  0,  0, 20,  0},
    {  0, 80,  0,  0,  1, 84,  0,  0,  2, 80,  0,  0,  1,148,  0,  0,
       1,100,  0,  0,  5, 84,  0,  0,  0, 85,  8,  0,  0, 21, 66,  0,
       0,  5, 88,128,  0,  2, 72,128,  0,  0,166, 40,  0,  0, 41, 64,
       0,  1, 73, 80,  0,  1, 65, 64,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  4,  0,  0,  0, 21, 64,  0,  0, 21, 64,  0,  0,
      37, 64,  0,  0, 10,144, 32,  0,  5,148, 10,128,  5, 85, 72, 40,
      16, 85, 89,136,  0,  6,153,148,  0,  0, 42, 85,  0,  0,  6,148,
       0,  0, 20,  4,  0,  0, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0}},
   {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,
       0,  0,  5, 64,  4,  0,  1,  0,  5, 85,170,165, 21, 85, 89,149,
     170,149, 89,149, 85, 64,  8,128, 85,  0,170,168, 84,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16,  0,  0,  0, 20,  4,
       0,  0,  6,148,  0,  0, 42, 85,  0,  6,153,148, 16, 85, 89,136,
       5, 85, 72, 40,  5,148, 10,128, 10,144, 32,  0, 37, 64,  0,  0,
      21, 64,  0,  0, 21, 64,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 65, 64,  0,  1, 73, 80,
       0,  0, 41, 64,  0,  0,166, 40,  0,  2, 72,128,  0,  5, 88,128,
       0, 21, 66,  0,  0, 85,  8,  0,  5, 84,  0,  0,  1,100,  0,  0,
       1,148,  0,  0,  2, 80,  0,  0,  1, 84,  0,  0,  0, 80,  0,  0},
    {  0,  0, 20,  0,  0,  0, 21,  0,  0,  4,148,128,  0, 20,164,128,
       0, 18, 90,128,  0,  2,162,  0,  0, 10, 90,  0,  0,  5, 72,  0,
       0,  5, 72,  0,  0, 21,  0,  0,  0, 21,  0,  0,  0, 86, 64,  0,
       1, 89,  0,  0,  0, 25, 64,  0,  0, 25, 80,  0,  0,  5, 64,  0},
    {  0,  5, 64,  0,  0,  5, 72,  0,  0,  9, 72,  0,  0, 74,168,  0,
       1, 89, 72,  0,  0, 74,168,  0,  0,  9, 72,  0,  0,  9, 72,  0,
       0,  5, 64,  0,  0,  5, 64,  0,  0,  5, 64,  0,  0,  5,144,  0,
       0,  5,148,  0,  0, 21,149,  0,  0,  1,149,  0,  0,  0,149,  0},
    {  0, 16,  0,  0,  1, 86,128,  0,  0, 84,128,  0,  0,154, 32,  0,
       0,165, 32,  0,  1,106,160,  0,  5, 37,  8,  0,  0,  9, 64,  0,
       0,  9, 64,  0,  0,  5, 80,  0,  0,  1, 84,  0,  0,  1,105, 80,
       0,  0, 89, 80,  0,  0, 89, 84,  0,  1,  2, 80,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0, 32,  0,  0,  1, 32,  0,  0,  5, 74,  0,  0,
       5, 96,128,  0,  2,154, 32,  0,  0,161,  0,  0,  5, 37, 64,  0,
       5,  9, 80,  0,  0,  1, 85, 68,  0,  0, 86, 85,  0,  0, 21,149,
       0,  0,  5,100,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10,128,  0,  0,
      16,168,  0,  0, 85,138,128,  0, 86,100,  0,  4, 10,101, 65, 21,
       0,169, 86, 85,  5,  9, 85,169,  1, 64, 21, 84,  0,  0,  1, 64,
       0,  0,  0, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0, 21, 42,170,  0, 85,  2, 32,  1, 85, 86,101, 86,170,
      86,101, 85, 84, 90,170, 85, 80,  0, 64,  0, 16,  1, 80,  0,  0,
       0, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0, 16,  0,  0,  1, 84,  0,  0,  1, 84,
       0,  0,  1, 88,  0,  8,  6,160,  2,160, 22, 80, 40, 33, 85, 80,
      34,101, 85,  4, 22,102,144,  0, 85,168,  0,  0, 22,144,  0,  0,
      16, 20,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  5,  0,  0,  0, 21, 64,  0,  0,  5,128,  0,  0, 22, 64,
       0,  0, 25, 64,  0,  0, 21, 80,  0, 32, 85,  0,  0,129, 84,  0,
       2, 37, 80,  0,  2, 33,128,  0, 40,154,  0,  0,  1,104,  0,  0,
       5, 97, 64,  0,  1, 65, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  1, 80,  0,  0,  5,100,  0,  0,  1,100,  0,  0,  0,101, 64,
       0,  1,149,  0,  0,  0, 84,  0,  0,  0, 84,  0,  0, 33, 80,  0,
       0, 33, 80,  0,  0,165,160,  0,  0,138,128,  0,  2,165,132,  0,
       2, 26, 20,  0,  2, 22, 16,  0,  0, 84,  0,  0,  0, 20,  0,  0},
    {  0, 86,  0,  0,  0, 86, 64,  0,  0, 86, 84,  0,  0, 22, 80,  0,
       0,  6, 80,  0,  0,  1, 80,  0,  0,  1, 80,  0,  0,  1, 80,  0,
       0, 33, 96,  0,  0, 33, 96,  0,  0, 42,161,  0,  0, 33,101, 64,
       0, 42,161,  0,  0, 33, 96,  0,  0, 33, 80,  0,  0,  1, 80,  0},
    {  0,  0,  0,  0,  5,128, 64,  0, 21,101,  0,  0,  5,101,  0,  0,
       5,105, 64,  0,  0, 21, 64,  0,  0,  5, 80,  0,  0,  1, 96,  0,
       0,  1, 96,  0,  0, 32, 88, 80,  0, 10,169, 64,  0,  8, 90,  0,
       0,  8,166,  0,  0,  2, 21,  0,  0,  2,149, 64,  0,  0,  4,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0, 16,  0,  0, 25, 80,  0,  0,
      86, 84,  0,  0, 85,149,  0,  0, 17, 85, 64,  0,  0,  5, 96, 80,
       0,  1, 88, 80,  0,  0, 74,  0,  0,  8,166,128,  0,  2,  9, 80,
       0,  0,161, 80,  0,  0,  8, 64,  0,  0,  8,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,
       1, 64,  0,  0, 21, 84,  1, 64,106, 85, 96, 80, 85,149,106,  0,
      84, 65, 89,160, 16,  0, 25,149,  0,  2,162, 85,  0,  0, 42,  4,
       0,  0,  2,160,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}}},
  {{{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     168,  0,  0,  0,170,  0, 85, 84,170,128,  4, 64, 85,106,166,106,
      42,170,166,106, 10,170, 85, 90,  8,  0,  2,  0,  0,  0, 10,128,
       0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 80,
       0,  0, 21,  8,  0,  1, 81,170, 32,  0, 38,106,168,130,166, 80,
     170,106,149,  0,149,170,144,160, 42,168,  2,128,  2,128,  0,  0,
       2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  4,128,  0,  0, 82,160,
       0,  1,  6,160,  0,  4, 89, 64,  0,  0,133,  0,  0,  2,164,160,
       0, 10,144,160, 34,170,128,  0,170,106,  0,  0,169,168,  0,  0,
      38,160,  0,  0,  0, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  8,  0,  0,  1,106,128,  0,  1, 42,  0,  0,  4, 89,  0,
       0,  4,165,  0,  0,  5, 86,128,  0, 16,164,160,  0,  2,144,  0,
       0,  2,144,  0,  0, 10,160,  0,  0, 42,128,  0, 10,150,128,  0,
      10,154,  0,  0, 42,154,  0,  0, 10, 64,128,  0,  0,  0,  0,  0},
    {  0,  2,160,  0,  0, 18,160,  0,  0, 18,144,  0,  0, 21, 82,  0,
       0, 18,154,128,  0, 21, 82,  0,  0, 18,144,  0,  0, 18,144,  0,
       0,  2,160,  0,  0,  2,160,  0,  0,  2,160,  0,  0,  9,160,  0,
       0, 41,160,  0,  0,169,168,  0,  0,169,128,  0,  0,169,  0,  0},
    {  0, 40,  0,  0,  0,168,  0,  0,  1, 41, 32,  0,  1, 37, 40,  0,
       1, 90, 72,  0,  0, 69, 64,  0,  0, 90, 80,  0,  0, 18,160,  0,
       0, 18,160,  0,  0,  0,168,  0,  0,  0,168,  0,  0,  2,106,  0,
       0,  0,154,128,  0,  2,152,  0,  0, 10,152,  0,  0,  2,160,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  2,130,128,  0, 10,146,128,  0,
       2,148,  0,  0, 20,101,  0,  0,  1, 18, 64,  0,  1, 26,160,  0,
       0, 66,168,  0,  0, 16,170,  0,  0,  0, 42,160,  0,  0, 38,128,
       0,  0, 41,128,  0,  0, 10, 64,  0,  0, 42,128,  0,  0, 10,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,  0,  0, 32, 40,  0,  0,
      41, 96,  0,  0,170, 84,  0,  0, 41,153, 96,  0, 17,154,170,  8,
      20, 18,170,160,  1, 80, 41,160,  0,  4,  9, 80,  0,  0,  2,164,
       0,  0,  2,168,  0,  0,  2,168,  0,  0,  0, 32,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,  0,
       2,160,  0,  0,  0,128,  0, 32,165, 85,170,160,169,154,170,168,
     169,154,169, 85,  1, 16,  2,170, 21, 85,  0,170,  0,  0,  0, 42,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,
       0,  0,  2,128,  2,128, 42,168, 10,  6,170, 86,  0, 86,169,170,
       5,154,130, 42,169,152,  0,  8,170, 69, 64,  0, 32, 84,  0,  0,
       5, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,  0,  0,  0, 10,152,
       0,  0, 42,106,  0,  0,169,170,  0,  2,170,136, 10,  6,160,  0,
      10, 26,128,  0,  0, 82,  0,  0,  1,101, 16,  0, 10,144, 64,  0,
      10,133,  0,  0,  2, 16,  0,  0,  0, 16,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  2,  1,160,  0,  0,166,168,  0,  0,166,160,
       0,  2,150,160,  0,  2,168,  0,  0, 10,160,  0,  0,  6,128,  0,
       0,  6,128,  0, 10, 26,  4,  0,  2,149, 80,  0,  0, 90, 16,  0,
       0,101, 16,  0,  0,168, 64,  0,  2,169, 64,  0,  0, 32,  0,  0},
    {  0,  0,106,  0,  0,  2,106,  0,  0, 42,106,  0,  0, 10,104,  0,
       0, 10, 96,  0,  0, 10,128,  0,  0, 10,128,  0,  0, 10,128,  0,
       0,  6,132,  0,  0,  6,132,  0,  0,133, 84,  0,  2,166,132,  0,
       0,133, 84,  0,  0,  6,132,  0,  0, 10,132,  0,  0, 10,128,  0},
    {  0, 10,128,  0,  0, 38,160,  0,  0, 38,128,  0,  2,166,  0,  0,
       0,169,128,  0,  0, 42,  0,  0,  0, 42,  0,  0,  0, 10,132,  0,
       0, 10,132,  0,  0,  5,165,  0,  0,  1, 81,  0,  0, 33,165, 64,
       0, 40, 88, 64,  0,  8,104, 64,  0,  0, 42,  0,  0,  0, 40,  0},
    {  0,160,  0,  0,  2,168,  0,  0,  1,160,  0,  0,  2,104,  0,  0,
       2,152,  0,  0, 10,168,  0,  0,  0,170,  4,  0,  0, 42,129,  0,
       0, 10,164, 64,  0,  1,132, 64,  0,  0, 89, 20,  0,  0, 22,128,
       0,  2,134,160,  0,  2,130,128,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  8,  0,  0,  0, 42,128,  0,  0, 42,128,  0,  0,
      26,128,  0,  0,  5, 96, 16,  0, 10,104,  5, 64, 10,170,132, 20,
      32,170,166, 68,  0,  9,102,104,  0,  0, 21,170,  0,  0,  9,104,
       0,  0, 40,  8,  0,  0, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0}},
   {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,
       0,  0, 10,128,  8,  0,  2,  0, 10,170, 85, 90, 42,170,166,106,
      85,106,166,106,170,128,  4, 64,170,  0, 85, 84,168,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 32,  0,  0,  0, 40,  8,
       0,  0,  9,104,  0,  0, 21,170,  0,  9,102,104, 32,170,166, 68,
      10,170,132, 20, 10,104,  5, 64,  5, 96, 16,  0, 26,128,  0,  0,
      42,128,  0,  0, 42,128,  0,  0,  8,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,128,  0,  2,134,160,
       0,  0, 22,128,  0,  0, 89, 20,  0,  1,132, 64,  0, 10,164, 64,
       0, 42,129,  0,  0,170,  4,  0, 10,168,  0,  0,  2,152,  0,  0,
       2,104,  0,  0,  1,160,  0,  0,  2,168,  0,  0,  0,160,  0,  0},
    {  0,  0, 40,  0,  0,  0, 42,  0,  0,  8,104, 64,  0, 40, 88, 64,
       0, 33,165, 64,  0,  1, 81,  0,  0,  5,165,  0,  0, 10,132,  0,
       0, 10,132,  0,  0, 42,  0,  0,  0, 42,  0,  0,  0,169,128,  0,
       2,166,  0,  0,  0, 38,128,  0,  0, 38,160,  0,  0, 10,128,  0},
    {  0, 10,128,  0,  0, 10,132,  0,  0,  6,132,  0,  0,133, 84,  0,
       2,166,132,  0,  0,133, 84,  0,  0,  6,132,  0,  0,  6,132,  0,
       0, 10,128,  0,  0, 10,128,  0,  0, 10,128,  0,  0, 10, 96,  0,
       0, 10,104,  0,  0, 42,106,  0,  0,  2,106,  0,  0,  0,106,  0},
    {  0, 32,  0,  0,  2,169, 64,  0,  0,168, 64,  0,  0,101, 16,  0,
       0, 90, 16,  0,  2,149, 80,  0, 10, 26,  4,  0,  0,  6,128,  0,
       0,  6,128,  0,  0, 10,160,  0,  0,  2,168,  0,  0,  2,150,160,
       0,  0,166,160,  0,  0,166,168,  0,  2,  1,160,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0, 16,  0,  0,  2, 16,  0,  0, 10,133,  0,  0,
      10,144, 64,  0,  1,101, 16,  0,  0, 82,  0,  0, 10, 26,128,  0,
      10,  6,160,  0,  0,  2,170,136,  0,  0,169,170,  0,  0, 42,106,
       0,  0, 10,152,  0,  0,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5, 64,  0,  0,
      32, 84,  0,  0,170, 69, 64,  0,169,152,  0,  8,  5,154,130, 42,
       0, 86,169,170, 10,  6,170, 86,  2,128, 42,168,  0,  0,  2,128,
       0,  0,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0, 42, 21, 85,  0,170,  1, 16,  2,170,169,154,169, 85,
     169,154,170,168,165, 85,170,160,  0,128,  0, 32,  2,160,  0,  0,
       0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0, 32,  0,  0,  2,168,  0,  0,  2,168,
       0,  0,  2,164,  0,  4,  9, 80,  1, 80, 41,160, 20, 18,170,160,
      17,154,170,  8, 41,153, 96,  0,170, 84,  0,  0, 41, 96,  0,  0,
      32, 40,  0,  0,  0,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0, 10,  0,  0,  0, 42,128,  0,  0, 10, 64,  0,  0, 41,128,
       0,  0, 38,128,  0,  0, 42,160,  0, 16,170,  0,  0, 66,168,  0,
       1, 26,160,  0,  1, 18, 64,  0, 20,101,  0,  0,  2,148,  0,  0,
      10,146,128,  0,  2,130,128,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  2,160,  0,  0, 10,152,  0,  0,  2,152,  0,  0,  0,154,128,
       0,  2,106,  0,  0,  0,168,  0,  0,  0,168,  0,  0, 18,160,  0,
       0, 18,160,  0,  0, 90, 80,  0,  0, 69, 64,  0,  1, 90, 72,  0,
       1, 37, 40,  0,  1, 41, 32,  0,  0,168,  0,  0,  0, 40,  0,  0},
    {  0,169,  0,  0,  0,169,128,  0,  0,169,168,  0,  0, 41,160,  0,
       0,  9,160,  0,  0,  2,160,  0,  0,  2,160,  0,  0,  2,160,  0,
       0, 18,144,  0,  0, 18,144,  0,  0, 21, 82,  0,  0, 18,154,128,
       0, 21, 82,  0,  0, 18,144,  0,  0, 18,160,  0,  0,  2,160,  0},
    {  0,  0,  0,  0, 10, 64,128,  0, 42,154,  0,  0, 10,154,  0,  0,
      10,150,128,  0,  0, 42,128,  0,  0, 10,160,  0,  0,  2,144,  0,
       0,  2,144,  0,  0, 16,164,160,  0,  5, 86,128,  0,  4,165,  0,
       0,  4, 89,  0,  0,  1, 42,  0,  0,  1,106,128,  0,  0,  8,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0, 32,  0,  0, 38,160,  0,  0,
     169,168,  0,  0,170,106,  0,  0, 34,170,128,  0,  0, 10,144,160,
       0,  2,164,160,  0,  0,133,  0,  0,  4, 89, 64,  0,  1,  6,160,
       0,  0, 82,160,  0,  0,  4,128,  0,  0,  4,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,
       2,128,  0,  0, 42,168,  2,128,149,170,144,160,170,106,149,  0,
     168,130,166, 80, 32,  0, 38,106,  0,  1, 81,170,  0,  0, 21,  8,
       0,  0,  1, 80,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}}}};

unsigned char finalesprites[2][4][64]={
  {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 64,  0,
      0,  1, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 64,  0,  0, 10,160,  0,
      0, 10,160,  0,  0,  1, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 64,  0,  0,169,106,  0,
      0,  1, 64,  0,  0, 42,168,  0,  0,  4, 16,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 64,  0,  0,  1, 64,  0,
      0,  1, 64,  0,170,169,106,170,  0,  1, 64,  0,  0,170,170,  0,
      0,  5, 80,  0,  0,  5, 80,  0, 42,170,170,168,  0, 16,  4,  0,
      0, 64,  1,  0,  0, 64,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0}},
  {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,128,  0,
      0,  2,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  2,128,  0,  0,  5, 80,  0,
      0,  5, 80,  0,  0,  2,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  2,128,  0,  0, 86,149,  0,
      0,  2,128,  0,  0, 21, 84,  0,  0,  8, 32,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
   {  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,128,  0,  0,  2,128,  0,
      0,  2,128,  0, 85, 86,149, 85,  0,  2,128,  0,  0, 85, 85,  0,
      0, 10,160,  0,  0, 10,160,  0, 21, 85, 85, 84,  0, 32,  8,  0,
      0,128,  2,  0,  0,128,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0}}};

/* Sprites new in Sopwith II */

unsigned char fallingsprites[2][64]={
  {  0, 10,170,170,  0,  2,165,168,  0,  0,165,160,  0,  0,  5,  0,
     0,  0,  5,  0,  0,  0,  5,  0,  0,  0, 21, 64,  0,  0, 21, 64,
     0,  0, 21, 64,  0,  0, 21, 64, 10,170,165,170,170,170,165,168,
   170,170,165,170,170,170,165,162,  0,  0, 21, 64,  0,  0, 21, 64},
  {  0,  0,149,  0,  0,  1,149,  0,  0, 21,149,  0,  0,  5,148,  0,
     0,  5,144,  0,  0,  5, 64,  0,  0,  5, 64,  0,  0,  5, 64,  0,
     0,  9, 72,  0,  0,  9, 72,  0,  0, 74,168,  0,  1, 89, 72,  0,
     0, 74,168,  0,  0,  9, 72,  0,  0,  5, 72,  0,  0,  5, 64,  0}};

unsigned char flocksprites[2][64]={
  { 48,  0,  0,  0,204,  0,  0,  0,  0,  3, 48, 12,  3,  0,192, 51,
    12,192,  0,  0,  0,  0,  0,  0,204, 51,  0,192, 48, 12,  3, 48,
     0,  0,  0,  0, 12,195,  0,204,  3, 12,192, 48,  0,  0,  0,  0,
     3,  0, 12,  0, 12,192, 51,  0,  0, 12,192,  0,  0,  3,  0,  0},
  {204,  0,  0,  0, 48,  0,  0,  0,  0,  0,192, 51, 12,195, 48, 12,
     3,  0,  0,  0,  0,  0,  0,  0, 48, 12,  3, 48,204, 51,  0,192,
     0,  0,  0,  0,  3, 12,192, 48, 12,195,  0,204,  0,  0,  0,  0,
    12,192, 51,  0,  3,  0, 12,  0,  0,  3,  0,  0,  0, 12,192,  0}};

unsigned char birdsprites[2][2]={
  { 48,204},
  {204, 48}};

unsigned char cowsprites[2][64]={
  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0, 12, 48,  0,  0, 14,160,  0,  0, 11,124,
     2,170,186,252, 42,170,186,251,234,170,186,188,234,170,175,  0,
   234,170,170,  0,232,160,162,128, 40,160,162,128, 60,240,243,192},
  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,
    10,170,162,160,239,170,250,188,234,170,170,188,235,235,226,176}};
