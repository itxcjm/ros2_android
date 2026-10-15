// Android NDK 不带 OpenSSL。ORB-SLAM3 只用 MD5_* 计算词表指纹
// （保存/加载 Atlas 时比对），这里用 FNV-1a 提供同样的接口，不涉及安全性。
#pragma once
#include <cstddef>
#include <cstdint>

#define MD5_DIGEST_LENGTH 16

typedef struct {
  std::uint64_t hash;
  std::uint64_t count;
} MD5_CTX;

inline void MD5_Init(MD5_CTX *ctx) {
  ctx->hash = 1469598103934665603ULL;
  ctx->count = 0;
}

inline void MD5_Update(MD5_CTX *ctx, const void *data, std::size_t len) {
  const unsigned char *bytes = static_cast<const unsigned char *>(data);
  for (std::size_t i = 0; i < len; ++i) {
    ctx->hash ^= bytes[i];
    ctx->hash *= 1099511628211ULL;
  }
  ctx->count += len;
}

inline void MD5_Final(unsigned char out[MD5_DIGEST_LENGTH], MD5_CTX *ctx) {
  std::uint64_t h = ctx->hash;
  for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
    out[i] = static_cast<unsigned char>((h >> (i * 8)) & 0xFFu);
    h ^= (h << 7);
  }
}