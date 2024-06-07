#include <iostream>
#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

//响应窗体变化函数
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    std::cout<<"Window size"<<width<<","<<height<<std::endl;
    //更新视口大小
    glViewport(0, 0, width, height);
};

//键盘消息回调函数
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_W){

    }
    if (action == GLFW_PRESS)
    {
        /* code */
    }
    if (action == GLFW_RELEASE)
    {
        /* code */
    }
    if(mods == GLFW_MOD_CONTROL){
        /* code */
    }
    if(mods == GLFW_MOD_SHIFT){
        /* code */
    }
    std::cout<<"press"<<key<<std::endl;
    std::cout<<"action:"<<action<<std::endl;
    std::cout<<"mods:"<<mods<<std::endl; 
    
}
void processInput(GLFWwindow *window);

int main(int, char **)
{
    //初始化GLFW环境
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //设置主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //设置次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //设置OpenGL配置文件核心模式
#ifdef __APPLE__
//如果使用的是Mac OS X系统，你还需要加下面这行代码到你的初始化代码中这些配置才能起作用
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    //创建窗口对象
    GLFWwindow *window = glfwCreateWindow(800, 600, "study OPenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "fail to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); //将该窗口为绘制环境

    //设置监听窗体大小变化消息
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //设置键盘消息回调函数
    glfwSetKeyCallback(window, keyCallBack);

    //glad 加载openGL函数
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "fail to init glad" << std::endl;
        return -1;
    }

    //设置 OpenGL 视口以及清理颜色
    glViewport(0, 0, 800, 600);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //执行窗体循环
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents(); //接受并分发窗口消息
        glClear(GL_COLOR_BUFFER_BIT); //清理颜色缓冲区
        //渲染操作
        //切换双缓存
        glfwSwapBuffers(window); 
    }
}

