import pandas as pd
import matplotlib.pyplot as plt

plt.style.use("bmh")

def simulation_results():
    df_sim = pd.read_csv("sim_results.txt",sep=',',skiprows=(0),header=(0))

    plt.figure()
    plt.plot(df_sim["t (s)"], df_sim["y"])
    plt.xlabel("t (s)")
    plt.ylabel("output amplitude (-)")
    plt.title("Output Response")

    plt.figure()
    plt.plot(df_sim["t (s)"], df_sim["u"])
    plt.xlabel("t (s)")
    plt.ylabel("input amplitude (-)")
    plt.title("Control Input")

if __name__ == "__main__":
    simulation_results()

    plt.draw()
    plt.pause(1)
    input("press to close")
    plt.close()