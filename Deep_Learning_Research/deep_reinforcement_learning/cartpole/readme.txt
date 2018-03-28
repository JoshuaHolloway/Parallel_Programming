This is me getting the inverted pendulum to learn bow to balance itself. -josh

Run an instance of the CartPole environment for 1000 timesteps:

	import gym
	env = gym.make('CartPole-v0')
	env.reset()
	for _ in range(1000):
	    env.render()
	    env.step(env.action_space.sample()) # take a random action

The environment’s step function returns four values:

1.observation (object): 
    An environment-specific object representing your observation of the environment. 
    For example, pixel data from a camera, joint angles and joint velocities of a robot, 
    or the board state in a board game.

2.reward (float): 
    Amount of reward achieved by the previous action. 
    The scale varies between environments, but the goal is always to increase your total reward.

3.done (boolean): 
    Whether it’s time to reset the environment again. 
    Most (but not all) tasks are divided up into well-defined episodes, and done being True 
    indicates the episode has terminated. 
    (For example, perhaps the pole tipped too far, or you lost your last life.)

4.info (dict): 
    Diagnostic information useful for debugging. 
    It can sometimes be useful for learning (for example, it might contain the raw probabilities 
    behind the environment’s last state change). 
    However, official evaluations of your agent are not allowed to use this for learning.

# ==============================================================================================

This is just an implementation of the classic “agent-environment loop”. 

Each timestep, the agent chooses an action, and the environment returns 
an observation and a reward.

The process gets started by calling reset(), which returns an initial observation. 

So a more proper way of writing the previous code would be to respect the done flag:

	import gym
	env = gym.make('CartPole-v0')
	for i_episode in range(20):
	    observation = env.reset()
	    for t in range(100):
		env.render()
		print(observation)
		action = env.action_space.sample()
		observation, reward, done, info = env.step(action)
		if done:
		    print("Episode finished after {} timesteps".format(t+1))
		    break

# ==============================================================================================

Spaces

In the examples above, we’ve been sampling random actions from the environment’s action space. 

But what actually are those actions? 

Every environment comes with an action_space and an observation_space. 

These attributes are of type Space, and they describe the format of valid actions and observations:

	import gym
	env = gym.make('CartPole-v0')
	print(env.action_space)
	#> Discrete(2)
	print(env.observation_space)
	#> Box(4,)


