
# Implementation of Principal Policy Optimization Deep Reinforcement Learning algorithm with Intel's Coach and Tensorflow

# OpenAI's PPO Algorithm:
## Blog:
https://blog.openai.com/openai-baselines-ppo/

## Github for Baselines:
https://github.com/openai/baselines

## OpenAI Gym with github and docs:
https://gym.openai.com/


# Intel Coach:
## Github:
https://github.com/NervanaSystems/coach

## Blog:
https://ai.intel.com/reinforcement-learning-coach-intel/

## Wiki:
http://coach.nervanasys.com/

## ==========================

## To install intel's coach and run the code:
$ python -V # Python 2.7 was the default version in successful install
$ git clone https://github.com/NervanaSystems/coach.git
$ cd coach

# Note - select no to neon due to a conflict with MKL
$ ./install.sh
$ source coach_env/bin/activate
$ python3 coach.py -r -p CartPole_PG


