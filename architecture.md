Implementing Adam Algorithm influenced by https://github.com/pytorch/pytorch/blob/b7bda236d18815052378c88081f64935427d7716/torch/optim/adam.py#L6

Adam: A Method for Stochastic Optimization`_.
    The implementation of the L2 penalty follows changes proposed in
    `Decoupled Weight Decay Regularization`_.


Params: defining params groups
- params (iterable): iterable of parameters to optimize or docts defining groups
    - lr (float, optional - learning rate (default 1e -3))
    - beta (tuple[float, float], optional): coefficients running averages of gradient and its square (default (0.9, 0.999)) eps (float, optional): term added to demoinator to improve numerical stablilty ( default: 1e-8)
    - weight_decay: float: L2 penalty default 0, amsgrad - boolean, whether to use the AMSGrad variant of this algorithm (default False)

a single optimization step
    args: 
        - closure (callable, optional): revaluates the model and returns the loss


