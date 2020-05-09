#include "../../lem_in.h"

void   paths(t_staend **staend,t_room **rooms, t_paths **paths){
    t_room *septr; //staend pointer
    t_room *rptr;  //room pointer

    septr = (*staend)->start;
    //for each starting room
    while (septr){
        //for each starting rooms links
        while (septr->links){
            // if start link = end
            if (ft_strcmp(septr->links->name,(*staend)->end->name) == 0){
                //end reached
                addEndToPath();
            }else{

            }     
        }
        septr = septr->next;
    }
}