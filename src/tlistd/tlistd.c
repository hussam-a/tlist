/*
	Hussam Ashraf El-Araby
	Operating Syste Concepts Ninth Edition
	Chapter  Project 2
	
	Task Lister (Depth First Search)
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/printk.h>

void dfs(struct task_struct *task)
{
	struct task_struct *next_task;
	struct list_head *list;

	printk(KERN_INFO "PID: %d    State: %ld    Name: %s\n", task->pid, task->state, task->comm);

	list_for_each(list, &task->children) 
	{
		next_task = list_entry(list, struct task_struct, sibling);
		dfs(next_task);
	}
}

/* This function is called when the module is loaded. */
int simple_init(void)
{
	printk(KERN_INFO "Loading tlist DFS Module\n");
	dfs(&init_task);
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

