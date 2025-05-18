#include <sys/types.h>
#include <optional>
#include <map>
#include <string>
#include <vector>

struct BlockReplicaLocation {
	int32_t data_server_id;
	std::string chunk_handle;
};

struct Inode {
	int64_t inode_id = 0;
	mode_t mode = 0;
	nlink_t nlink;
	uid_t uid = 0;
	gid_t gid = 0;
	off_t size;

	struct timespec access_time = {0, 0};
	struct timespec modification_time = {0, 0};
	struct timespec change_time = {0, 0};

	std::optional<std::map<std::string, int64_t>> directory_entries;
	std::optional<std::map<int32_t, std::vector<BlockReplicaLocation>>>
      file_chunks;
};

