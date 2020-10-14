#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <kvm.h>
#include <dirent.h>
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <sys/proc.h>
#include <sys/param.h>
#include <libprocstat.h>
#include <sys/user.h>
#include <sys/wait.h>

class Log{
	public: 
	Log(const std::vector<std::string>& filenames);
	int write_message(const std::string& message, int log_num);
	
	~Log();
	
	private:
	void die();
	int* last_ptr;
	std::vector<void*> pointers;
	int logger_pid;
	bool good;
};
