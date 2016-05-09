/*
Part of tlist (github.com/hussam-a/tlist)
Authors:
Hussam A. El-Araby (github.com/hussam-a)

Project code and configurations are under the GNU GPL license (tlist/LICENSE) 
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/printk.h>

char spaces[1000];

void dfs(struct task_struct *task, int n)
{
	struct task_struct *next_task;
	struct list_head *list;
	
	int i = 0;
	int j = n;
	for (; i < j ; i = i +1)
	{
		spaces[i] = ' ';
	}
	spaces[j] = '\0';	
	
	printk(KERN_INFO "%s|_PID: %d    State: %ld    Name: %s\n", spaces, task->pid, task->state, task->comm);

	list_for_each(list, &task->children) 
	{
		next_task = list_entry(list, struct task_struct, sibling);
		n= n+1;
		dfs(next_task,n);
	}
}

/* This function is called when the module is loaded. */
int simple_init(void)
{
	printk(KERN_INFO "Loading tlist DFS Module\n");
	dfs(&init_task, 0);
	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) 
{
	printk(KERN_INFO "Removing tlist DFS Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("tlistd");
MODULE_AUTHOR("Hussam A. El-Araby");

