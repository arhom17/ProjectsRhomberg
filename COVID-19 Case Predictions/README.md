# COVID-19 Case Prediction Project

 In the light of the SARS-CoV-2 outbreak and being forced to continue my studies at home, I have grown increasingly bored and have gained a recent interest in studying the math behind disease outbreaks. Now, when considering any disease there are tons of factors that exist, as we have seen with COVID-19: age, population density, timing, series intervals, etc.

One of the most common ways to look at an outbreak is to use the SIR model, analyzing those who are susceptible, Infected, and Removed (recovered or died). The sum of those should equal the population as a whole. An important number to note with any disease is R0, the rate at which the disease spreads. If R0 is < 1, the disease spreads too slow and will die out, but a R0 > 1 will see a growth.

The average R0 for influenza tends to rest around 1.3-1.5 depending on the year. COVID-19, as some predict, has a R0 of 1.5-3.5, depending on certain factors. Professionals are advising that we STAY AT HOME during these times of spread as a way to lower R0. If there are less people around each other, there is a smaller chance the disease will spread as it has nowhere to go.

One of the major problems with COVID-19 has been the series interval, or the time it takes for an infected person to start showing symptoms. This is a factor that has made R0 large as people tend to ‘feel fine’ for 5-10 days before symptoms start to show, even though they are contagious. By then, it is too late and they have given the disease to 1 or 4 people on average. Another factor that has increased the spread has been a result of the lack of testing efforts within the United States. China and South Korea were able to quickly organize their testing and contact tracing efforts, allowing them to confirm cases of COVID-19 at a semi-controlled rate. With a disease that sees great exponential growth, it is hard to know when we are winning until the curve starts to go down. However, we can’t know when the curve starts to go down unless we can test and see who has it for sure in all cases. With a lack of testing, we never know exactly how many people have COVID-19, but we can try to predict it.

Americans tend to see problems as minor issues until it’s too late. There are many ways to forecast a disease, but I have put some numbers together (based on an analysis by Tomas Puero) to show Iowa that it has already been ‘too late’, and it is extremely important that we follow the recommendations being given by professionals.

The death rate for COVID-19 within the United States at the time of writing this is currently ~1.76%. If we make the lenient assumption that a person dies on average the 14th day of having COVID-19, then we can predict with this number that 57 people had COVID-19 13 days before the first death occurred in Iowa. Looking at this exponentially, if we assume no social distancing and a R0 of 2.5, Iowa would have been completely infected by day 13 of this spread. However, what is not accounted for in this model that the SIR model shows is logistic growth. As time goes on, susceptible people become harder to find as more become infected or recover. The numbers presented here are simply to show theory.

Fortunately for Iowans, we have been doing a decent job of social distancing, and naturally have more space between each other in comparison to other states. If we assume that R0 in Iowa is around 1.5, then after the first death we can figure there are 11,093 cases that have already spread (not using the SIR logistic approach). At the time of writing this, Iowa only has 472 confirmed cases of COVID-19. The warning here is that this number is not an accurate representation of how many people in Iowa could actually have it. So far, 7 people have died from COVID-19 which could mean upwards of 77,653 people across the state have been infected.

While there are many other factors that go into disease forecasting, this is just a simple model to create assumptions of how many people might have gotten the disease within a population. From my understanding, Iowa medical teams have been working tirelessly to not only provide for those who are infected with COVID-19, but also for those who are in need of attention for other medical reasons. The 14 day assumption was used to show the effects of spread if we did not follow the stay at home or self-quarantine rules. While these numbers are all assumptions, we won’t know for sure until new, better, and faster testing methods are provided, along with effective tracing methods. Instead, they can serve as a warning of what could be out there, the next time you leave your house.

By: Alex Rhomberg

Sources:
Tomas Pueyo: https://medium.com/…/coronavirus-act-today-or-people-will-d…
COVID-19 Death Rate USA: 2,384 / 135,502 = 1.76%: https://www.google.com/covid19-map/
COVID-19 Recovery Rate USA: 4,378 / 135,502 = 3.23%: https://www.google.com/covid19-map/
Confirmed Cases in Iowa: 472: https://idph.iowa.gov/Emerging-Health-Iss…/Novel-Coronavirus
Confirmed Deaths in Iowa: 7: https://www.worldometers.info/coronavirus/country/us/
R0 believed to be 1.5 to 3.5: https://labblog.uofmhealth.org/…/how-scientists-quantify-in…
