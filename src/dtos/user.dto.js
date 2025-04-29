export const bodyToUser = (body) => {
    const birth = new Date(body.birth);

    return {
        email: body.email,
        name: body.name,
        gender: body.gender,
        birth,
        address: body.address || "",
        detailAddress: body.detailAddress || "",
        phoneNumber: body.phoneNumber,
        preferences: body.preferences,
    };
};

export function responseFromUser({user,preferences}){
    if(!Array.isArray(user) || user.length === 0 ){
        throw new Error("User not found");
    } 

    const u = user[0];

    return {
        memberId: u.id,
        email: u.email,
        name: u.name,
        gender: u.gender,
        birth: u.birth.toISOString(),
        address: u.address,
        detailAddress: u.detail_address,
        phoneNumber: u.phone_number,
        preferences: preferences.map((p) => ({
          categoryId: p.food_category_id,
          categoryName: p.name
        }))
      };

}