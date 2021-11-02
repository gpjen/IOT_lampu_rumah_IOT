-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Waktu pembuatan: 26 Jun 2021 pada 14.06
-- Versi server: 10.4.19-MariaDB
-- Versi PHP: 7.4.20

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `erik_relay`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `relay`
--

CREATE TABLE `relay` (
  `relay_id` int(11) NOT NULL,
  `nama_relay` varchar(64) NOT NULL,
  `logika` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data untuk tabel `relay`
--

INSERT INTO `relay` (`relay_id`, `nama_relay`, `logika`) VALUES
(1, 'LAMPU 1', 1),
(2, 'LAMPU 2', 1),
(3, 'LAMPU 3', 1),
(4, 'LAMPU 4', 0);

--
-- Indexes for dumped tables
--

--
-- Indeks untuk tabel `relay`
--
ALTER TABLE `relay`
  ADD PRIMARY KEY (`relay_id`);

--
-- AUTO_INCREMENT untuk tabel yang dibuang
--

--
-- AUTO_INCREMENT untuk tabel `relay`
--
ALTER TABLE `relay`
  MODIFY `relay_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
