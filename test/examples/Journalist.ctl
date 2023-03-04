CrowdTask Journalist {
    Constraints: 
        Spatial: 
            (108.80, 34.33) - (109.05, 34.20)
        Date: 
            FromNowTo(2023/6/30)
       

    Hparticipant: 
        Location
        HumanIntelligence
        image

    compute main(): Void = {
        CrowdOS.save("./data/",(Hpart.Pid, Hpart.Image))
    }
}

