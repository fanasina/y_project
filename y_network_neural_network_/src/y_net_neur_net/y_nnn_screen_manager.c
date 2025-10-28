/* file: y_network_neural_network/src/y_net_neur_net/y_nnn_screenmanager.c */
#include "y_net_neur_net/y_nnn_screen_manager.h"

#define SIZE_LOCAL_BUF 300

GEN_LIST_ALL(pid_t)


/* return max pidof target, and if m_pid_t is not NULL, put into it all pids */
pid_t max_pidof_to_list_pid_t(char *target, struct main_list_pid_t *m_pid_t){
  pid_t maxpid=0;
  struct dirent *entry;
  DIR *proc = opendir("/proc"); /*  */
  
  if(!proc){ /* fail */
    perror("opendir /proc");
    return -1;
  }
  /* loop on subdir of proc */
  while((entry=readdir(proc)) != NULL){
    int is_pid=1; /* init to not digit subdir */
    for(int i=0; entry->d_name[i]; ++i){
      if(!isdigit((unsigned char) entry->d_name[i])){
        is_pid=0;
        break;
      }
    }
    if(!is_pid) /* not pid i.e, exists i / is_pid == 0 */
      continue;
    
    char path[SIZE_LOCAL_BUF];
    snprintf(path,SIZE_LOCAL_BUF, "/proc/%s/comm",entry->d_name);

    int fd_comm = open(path, O_RDONLY);
    if(fd_comm<0){
      continue;
    }
    char name[SIZE_LOCAL_BUF];
    int status;
    if((status=read(fd_comm, name, SIZE_LOCAL_BUF))){
      name[status-1]=0;
      if(strcmp(name,target)==0){
        pid_t valpid=(pid_t)atol(entry->d_name);
        if(maxpid<valpid) maxpid=valpid;
        if(m_pid_t){
          push_back_list_pid_t(m_pid_t,valpid);
        }
      }
    }
    close(fd_comm);
  }
  closedir(proc);
  
  return maxpid;
}
/* to write in an open bash terminal */
int sprintbashpid(pid_t pid, char *content, size_t size_content){
  char duplicate_stdout_path[128];
  sprintf(duplicate_stdout_path,"/proc/%d/fd/1",pid);
  int fd_stdout=open(duplicate_stdout_path, O_WRONLY);
  if(fd_stdout >-1){
    write(fd_stdout,content,size_content);
    close(fd_stdout);
    return 0; 
  }
  else{
    perror("sprintbashpid\n");
    return -1;
  } 

}
