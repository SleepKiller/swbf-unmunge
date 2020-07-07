#pragma once

#include <cstdint>
#include <string>
#include <shlwapi.h>
#include <windows.h>

constexpr std::uint32_t fnv_1a_hash(const std::string_view str)
{
   constexpr std::uint32_t FNV_prime = 16777619;
   constexpr std::uint32_t offset_basis = 2166136261;

   std::uint32_t hash = offset_basis;

   for (auto c : str) {
      c |= 0x20;

      hash ^= c;
      hash *= FNV_prime;
   }

   return hash;
}

constexpr std::uint32_t operator""_fnv(const char* str, const std::size_t length)
{
   return fnv_1a_hash({str, length});
}

std::string lookup_fnv_hash(std::uint32_t hash);

// using  "user_hashes.txt"
// read line by line
void read_dictionary(const char* fileName);


#pragma comment(lib, "shlwapi.lib")

BOOL GetModuleDir(char* pBuf, DWORD dwBufSize);
